/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RaiseElevator.h"

RaiseElevator::RaiseElevator(Climb* climb) : m_climb{climb} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({climb});
}

// Called when the command is initially scheduled.
void RaiseElevator::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RaiseElevator::Execute() {}

// Called once the command ends or is interrupted.
void RaiseElevator::End(bool interrupted) {}

// Returns true when the command should end.
bool RaiseElevator::IsFinished() { return false; }
