#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() {
  // Implementation of subsystem constructor goes here.
  m_odometryHandler.resetEncoders();
  tankDrive(0, 0);
}

void DriveTrain::Periodic() {
  m_odometryHandler.updateOdometry();
}

void DriveTrain::arcadeDrive(float forward, float turn) {
  m_myRobot.ArcadeDrive(forward, turn);
}

void DriveTrain::tankDrive(float leftMotorValue, float rightMotorValue) {
  m_myRobot.TankDrive(leftMotorValue, rightMotorValue);
}

void DriveTrain::resetEncoders() {
  m_odometryHandler.resetEncoders();
}

double DriveTrain::getLeftEncoderValue() {
    return m_odometryHandler.getLeftEncoderValue();
}

double DriveTrain::getRightEncoderValue() {
    return m_odometryHandler.getRightEncoderValue();
}

double DriveTrain::getBotDirection() {
  return m_odometryHandler.getBotDirection();
}

double DriveTrain::getBotDistance() {
  return m_odometryHandler.getBotDistance();
}

double DriveTrain::getX() {
  return m_odometryHandler.getX();
}

double DriveTrain::getY() {
  return m_odometryHandler.getY();
}

void DriveTrain::resetDistance() {
  m_odometryHandler.resetDistance();
}