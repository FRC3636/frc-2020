/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurnToLemon.h"

TurnToLemon::TurnToLemon(DriveTrain* driveTrain, NetworkTableHandler* handler) : m_driveTrain{driveTrain}, m_handler{handler} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_driveTrain});
  AddRequirements({m_handler});
}

// Called when the command is initially scheduled.
void TurnToLemon::Initialize() {
  m_driveTrain->tankDrive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void TurnToLemon::Execute() {
  m_driveTrain->m_percentageTurnPID.setSetPoint(50);
  double v = m_driveTrain->m_percentageTurnPID.calculate(m_handler->getX());
  m_driveTrain->tankDrive(v, -v);
  std::cout << v << std::endl;
}

// Called once the command ends or is interrupted.
void TurnToLemon::End(bool interrupted) {
  m_driveTrain->tankDrive(0, 0);
}

// Returns true when the command should end.
bool TurnToLemon::IsFinished() { return std::abs(m_driveTrain->m_percentageTurnPID.calculate(m_driveTrain->getBotDirection())) < 0.05; }
