/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ConveyCells.h"

ConveyCells::ConveyCells(Conveyor* conveyor) : m_conveyor{conveyor} {
  AddRequirements(m_conveyor);
}

void ConveyCells::Initialize() {
  // At the begining, activate the conveyor
  m_conveyor->activateConveyor();
}

void ConveyCells::Execute() {}

void ConveyCells::End(bool interrupted) {
  // At the end, stop the intake
  m_conveyor->stopConveyor();
}

bool ConveyCells::IsFinished() { return false; }
