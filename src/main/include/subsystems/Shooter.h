/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Victor.h>
#include <frc/VictorSP.h>
#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void setShooter(bool shooting);
  void setLowerShooter(bool move);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Victor m_leftShooterMotor{constant::LEFT_SHOOTER_MOTOR_PORT};
  frc::Victor m_rightShooterMotor{constant::RIGHT_SHOOTER_MOTOR_PORT};
  frc::Victor m_lowerShooterMotor{constant::SHOOTER_BASE_MOTOR_PORT};
};
