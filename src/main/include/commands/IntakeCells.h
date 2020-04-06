/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Intake.h"

// ########## REVIEW ##########
// This command is meant to be active when the driver want to take cells
// This command only activate the intake (motor to 1)
// The logic (driver input) is on the RobotContainer side not on this command
class IntakeCells
    : public frc2::CommandHelper<frc2::CommandBase, IntakeCells> {
 public:
  IntakeCells(Intake* intake);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Intake* m_intake;
};
