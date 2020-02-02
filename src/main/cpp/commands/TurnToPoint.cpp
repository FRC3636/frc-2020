/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurnToPoint.h"

TurnToPoint::TurnToPoint(DriveTrain* driveTrain, float x, float y) : m_driveTrain{driveTrain}, m_targetX{x}, m_targetY{y} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({driveTrain});
}

// Called when the command is initially scheduled.
void TurnToPoint::Initialize() {
  //std::cout << "started" << std::endl;
  m_driveTrain->arcadeDrive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void TurnToPoint::Execute() {
  m_driveTrain->updateOdometry();
  std::cout << "Goal Angle: " << getAngle(m_targetX, m_targetY) << ", Bot Angle: " << m_driveTrain->getBotDirection() << std::endl;
  m_driveTrain->m_turnPID.setSetPoint(getAngle(m_targetX, m_targetY));
  double v = m_driveTrain->m_turnPID.calculate(m_driveTrain->getBotDirection());
  std::cout << "v: " << v << std::endl;
  m_driveTrain->tankDrive(-v, v);
}

// Called once the command ends or is interrupted.
void TurnToPoint::End(bool interrupted) {
  m_driveTrain->arcadeDrive(0, 0);
}

// Returns true when the command should end.
bool TurnToPoint::IsFinished() { 
  return std::abs(m_driveTrain->m_turnPID.calculate(m_driveTrain->getBotDirection())) < 0.3;
}

double TurnToPoint::getAngle(double x, double y) {
  double angle;
  if(x == 0 && y == 0) {
    angle = 0;
  } else {
    angle = std::atan(x / y);
  }
  /*if(y < 0 && x >= 0){
    angle += M_PI;
  } else if(y < 0 && x < 0){
    angle += M_PI;
    angle = -angle;
  }*/
  
  while(angle >= M_PI) {
    angle -= 2.0*M_PI;
  }
  while(angle <= -M_PI) {
    angle += 2.0*M_PI;
  }
  return angle;
}
