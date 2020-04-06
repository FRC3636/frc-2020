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
// Exactly like the IntakeCells command but to "outtake"
// I don't know if the word "outtake" is appropriate but I think this is what you wanted to do ...
class OuttakeCells
    : public frc2::CommandHelper<frc2::CommandBase, OuttakeCells> {
 public:
  OuttakeCells(Intake* intake);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Intake* m_intake;
};
