/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>
#include "Constants.h"

  // ########## REVIEW ##########
  // This subsystem control the conveyor (aka the lower Shooter)
  // I divided the Intake subsytem in two because these two mechanisms seems independant

class Conveyor : public frc2::SubsystemBase {
 public:
  Conveyor();

  // ########## REVIEW ##########
  // Exactly like for the intake, I separated your methods in two (without any argument):

  /**
   * Set the motor to 1
   */
  void activateConveyor();

  /**
   * Stop the motor
   */
  void stopConveyor();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::VictorSP m_lowerShooterMotor{constant::SHOOTER_BASE_MOTOR_PORT};
};
