#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() {
  // Implementation of subsystem constructor goes here.
  resetEncoders();
  m_imu.InitGyro();
  m_imu.Calibrate();
  tankDrive(0, 0);
}

void DriveTrain::Periodic() {
  updateOdometry();
}

void DriveTrain::updateOdometry() {
  double tR = -m_rightEncoder.Get() - m_oldTR;
  double tL = m_leftEncoder.Get() - m_oldTL;

  double dTheta = ((tR - tL)*0.0184)/(constant::WIDTH_BETWEEN_WHEELS);
  m_botDirection += dTheta;

  double dAV = ((tR + tL)*0.0184*2.54)/2.0;
  m_botDistance += dAV;

  m_velocity = dAV * 50.0;

  double dY = dAV * std::cos(m_botDirection);
  m_botY += dY;

  double dX = dAV * std::sin(m_botDirection);
  m_botX += dX;

  m_oldTR = -m_rightEncoder.Get();
  m_oldTL = m_leftEncoder.Get();

  std::cout << m_imu.GetAngle() << std::endl;
}

void DriveTrain::arcadeDrive(float forward, float turn) {
  m_myRobot.ArcadeDrive(forward, turn);
}

void DriveTrain::tankDrive(float leftMotorValue, float rightMotorValue) {
  m_myRobot.TankDrive(leftMotorValue, rightMotorValue);
}

void DriveTrain::resetEncoders() {
  m_rightEncoder.Reset();
  m_rightEncoder.SetSamplesToAverage(5);
  m_rightEncoder.SetMaxPeriod(10);
  m_rightEncoder.SetDistancePerPulse(1);

  m_leftEncoder.Reset();
  m_leftEncoder.SetSamplesToAverage(5);
  m_leftEncoder.SetMaxPeriod(10);
  m_leftEncoder.SetDistancePerPulse(1);

  m_imu.Reset();

  m_oldTR = 0.0;
  m_oldTL = 0.0;
  m_velocity = 0;
  m_botDistance = 0.0;
  m_botDirection = 0.0;
  m_botX = 0.0;
  m_botY = 0.0;
}

double DriveTrain::getBotDirection() {
  return m_botDirection;
}

double DriveTrain::getBotDistance() {
  return m_botDistance;
}

double DriveTrain::getX() {
  return m_botX;
}

double DriveTrain::getY() {
  return m_botY;
}

void DriveTrain::resetDistance() {
  m_botDistance = 0;
}