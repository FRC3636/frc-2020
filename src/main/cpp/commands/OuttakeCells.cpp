/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/OuttakeCells.h"

OuttakeCells::OuttakeCells(Intake* intake) : m_intake{intake} {
  AddRequirements(m_intake);
}

void OuttakeCells::Initialize() {
  // At the begining, activate the intake
  m_intake->activateIntakeReverse();
}

void OuttakeCells::Execute() {}

void OuttakeCells::End(bool interrupted) {
  // At the end, stop the intake
  m_intake->stopIntake();
}

bool OuttakeCells::IsFinished() { return false; }
