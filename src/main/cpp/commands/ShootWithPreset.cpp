/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShootWithPreset.h"

ShootWithPreset::ShootWithPreset(Shooter* shooter, double power, std::function<bool()> end) : m_shooter{shooter}, m_power{power}, m_end{end} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_shooter});
}

// Called when the command is initially scheduled.
void ShootWithPreset::Initialize() {
  m_shooter->setShooter(0);
}

void ShootWithPreset::Execute() {
  m_shooter->setShooter(m_power);
}

// Called once the command ends or is interrupted.
void ShootWithPreset::End(bool interrupted) {
  m_shooter->setShooter(0);
}

// Returns true when the command should end.
bool ShootWithPreset::IsFinished() { return m_end(); }
