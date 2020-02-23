/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShootBalls.h"

ShootBalls::ShootBalls(Shooter* shooter,std::function<bool()> end) : m_shooter{shooter}, m_end{end} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_shooter});
}

// Called when the command is initially scheduled.
void ShootBalls::Initialize() {
  m_shooter->setShooter(true);
}

// Called once the command ends or is interrupted.
void ShootBalls::End(bool interrupted) {
  m_shooter->setShooter(false);
}

// Returns true when the command should end.
bool ShootBalls::IsFinished() { return m_end(); }
