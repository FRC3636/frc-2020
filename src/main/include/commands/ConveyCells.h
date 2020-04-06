/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Conveyor.h"

// ########## REVIEW ##########
// Exactly like the IntakeCells and OuttakeCells commands but for the conveyor

class ConveyCells
    : public frc2::CommandHelper<frc2::CommandBase, ConveyCells> {
 public:
  ConveyCells(Conveyor* conveyor);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Conveyor* m_conveyor;
};
