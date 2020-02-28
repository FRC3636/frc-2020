/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveToPoint.h"

DriveToPoint::DriveToPoint(DriveTrain* driveTrain, double x, double y) : m_driveTrain{driveTrain}, m_targetX{x}, m_targetY{y} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({driveTrain});
}

// Called when the command is initially scheduled.
void DriveToPoint::Initialize() {
  m_targetX -= m_driveTrain->getX();
  m_targetY -= m_driveTrain->getY();
  m_driveTrain->arcadeDrive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void DriveToPoint::Execute() {
  std::cout << "drive" << std::endl;
  m_driveTrain->m_drivePID.setSetPoint(-getDistance(m_targetX, m_targetY));
  double v = m_driveTrain->m_drivePID.calculate(m_driveTrain->getBotDistance());
  m_driveTrain->tankDrive(v, v);
}

// Called once the command ends or is interrupted.
void DriveToPoint::End(bool interrupted) {
  m_driveTrain->arcadeDrive(0, 0);
  m_driveTrain->resetDistance();
}

// Returns true when the command should end.
bool DriveToPoint::IsFinished() { return std::abs(m_driveTrain->m_drivePID.calculate(m_driveTrain->getBotDistance())) < 0.05; }

double DriveToPoint::getDistance(double x, double y) {
  return std::sqrt(x*x + y*y);
}
