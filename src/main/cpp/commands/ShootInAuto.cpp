/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShootInAuto.h"

ShootInAuto::ShootInAuto(Intake* intake, Shooter* shooter) : m_intake{intake}, m_shooter{shooter} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_intake, m_shooter});
}

// Called when the command is initially scheduled.
void ShootInAuto::Initialize() {
  m_startTime = std::chrono::system_clock::now();
  m_shooter->setShooter(constant::AUTO_MOTOR_POWER);
}

// Called repeatedly when this Command is scheduled to run
void ShootInAuto::Execute() {
  m_intake->setLowerShooter(true);
  std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
  m_duration = currentTime - m_startTime;
}

// Called once the command ends or is interrupted.
void ShootInAuto::End(bool interrupted) {
  m_intake->setLowerShooter(false);
  m_shooter->setShooter(0);
}

// Returns true when the command should end.
bool ShootInAuto::IsFinished() { return m_duration.count() >= 5; }
