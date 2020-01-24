#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() {
  // Implementation of subsystem constructor goes here.
  TankDrive(0, 0);
}

void DriveTrain::ArcadeDrive(float forward, float turn) {
  m_myRobot.ArcadeDrive(forward, turn);
}

void DriveTrain::TankDrive(float leftMotor, float rightMotor) {
  m_myRobot.TankDrive(leftMotor, rightMotor);
}
