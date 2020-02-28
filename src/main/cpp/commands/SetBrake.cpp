/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetBrake.h"

SetBrake::SetBrake(Climb* climb, bool on, std::function<bool()> shouldEnd) : m_climb{climb}, m_on{on}, m_shouldEnd{shouldEnd} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_climb});
}

// Called when the command is initially scheduled.
void SetBrake::Initialize() {
  if(m_on) {
    m_climb->setBrakeMotor(1);
  } else {
    m_climb->setBrakeMotor(-1);
  }
}

// Called once the command ends or is interrupted.
void SetBrake::End(bool interrupted) {
  m_climb->setBrakeMotor(0);
}

// Returns true when the command should end.
bool SetBrake::IsFinished() { return m_shouldEnd(); }

void SetBrake::Execute() {}