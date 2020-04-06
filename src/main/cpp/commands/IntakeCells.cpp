/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/IntakeCells.h"

IntakeCells::IntakeCells(Intake* intake) : m_intake{intake} {
  AddRequirements(m_intake);
}

void IntakeCells::Initialize() {
  // At the begining, activate the intake
  m_intake->activateIntake();
}

void IntakeCells::Execute() {}

void IntakeCells::End(bool interrupted) {
  // At the end, stop the intake
  m_intake->stopIntake();
}

bool IntakeCells::IsFinished() { return false; }
