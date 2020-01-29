/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LowerElevator.h"

LowerElevator::LowerElevator(Climb* climb) : m_climb{climb} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({climb});
}

// Called when the command is initially scheduled.
void LowerElevator::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LowerElevator::Execute() {}

// Called once the command ends or is interrupted.
void LowerElevator::End(bool interrupted) {}

// Returns true when the command should end.
bool LowerElevator::IsFinished() { return false; }
