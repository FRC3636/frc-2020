/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Spark.h>
#include <frc/DigitalInput.h>

#include "Constants.h"

class Climb : public frc2::SubsystemBase {
 public:
  Climb();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void setMotor(double speed);
  void setBrakeMotor(double speed);
  bool getLowerLimitSwitch();
  bool getUpperLimitSwitch();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Spark m_elevatorMotor{constant::ELEVATOR_MOTOR_PORT};
  frc::Spark m_brakeMotor{constant::ELEVATOR_BRAKE_PORT};
};
