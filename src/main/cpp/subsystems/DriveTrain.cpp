#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() {
  // Implementation of subsystem constructor goes here.
  resetEncoders();
  tankDrive(0, 0);
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
}
