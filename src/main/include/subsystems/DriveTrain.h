#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/WPILib.h>
#include "Constants.h"
#include "commands/DriveWithJoysticks.h"

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();

  void ArcadeDrive(float forward, float turn);

  void TankDrive(float leftMotor, float rightMotor);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::VictorSP m_leftMotor{constant::LEFT_MOTOR_PORT};
  frc::VictorSP m_rightMotor{constant::RIGHT_MOTOR_PORT};
  frc::DifferentialDrive m_myRobot{m_leftMotor, m_rightMotor};
};
