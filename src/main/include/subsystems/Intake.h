/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>
#include <frc/Victor.h>
#include "Constants.h"

  // ########## REVIEW ##########
  // I moved the lower shooter from the intake subsystem to the Conveyor subsytem.
  // Indeed, it seems like the lower shooter and the intake are two independant mechanisms.
  // They have different functions : intaking and convey

class Intake : public frc2::SubsystemBase {
 public:
  Intake();

  // ########## REVIEW ##########
  // I find the function "setIntake(double intaking)" weird :
  // I would divide the method setIntake(double intaking) into these three methods

  /**
   * Set the motor to 1
   */
  void activateIntake();

    /**
   * Set the motor to -1
   */
  void activateIntakeReverse();

  /**
   * Stop the motor
   */
  void stopIntake();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::VictorSP m_intakeMotor{constant::INTAKE_MOTOR_PORT};
};
