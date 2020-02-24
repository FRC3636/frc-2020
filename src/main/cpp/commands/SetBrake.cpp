/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetBrake.h"

SetBrake::SetBrake(Climb* climb, bool on) : m_climb{climb}, m_on{on} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_climb});
}

// Called when the command is initially scheduled.
void SetBrake::Initialize() {
  if(m_on) {
    m_climb->setBrakeMotor(0.5);
  } else {
    m_climb->setBrakeMotor(-0.5);
  }
  m_startTime = std::chrono::system_clock::now();
}

void SetBrake::Execute() {
  std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
  m_duration = currentTime - m_startTime;
}

// Called once the command ends or is interrupted.
void SetBrake::End(bool interrupted) {
  m_climb->setBrakeMotor(0);
}

// Returns true when the command should end.
bool SetBrake::IsFinished() { return m_duration.count() >= 1; }
