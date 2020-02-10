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
void RaiseElevator::Initialize() {
  m_climb->setMotor(constant::RAISE_ELEVATOR_VALUE);
}

// Called once the command ends or is interrupted.
void RaiseElevator::End(bool interrupted) {
  m_climb->setMotor(constant::KEEP_ELEVATOR_LEVEL_VALUE);
}

// Returns true when the command should end.
bool RaiseElevator::IsFinished() { return m_climb->getUpperLimitSwitch(); }
