#include "commands/TurnToPoint.h"

TurnToPoint::TurnToPoint(DriveTrain* driveTrain, float x, float y, int shooterFront) : m_driveTrain{driveTrain}, m_targetX{x}, m_targetY{y}, m_shooterFront{shooterFront} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({driveTrain});
}

// Called when the command is initially scheduled.
void TurnToPoint::Initialize() {
  m_targetX -= m_shooterFront * m_driveTrain->getX();
  m_targetY -= m_shooterFront * m_driveTrain->getY();
  m_driveTrain->arcadeDrive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void TurnToPoint::Execute() {
  m_driveTrain->m_turnPID.setSetPoint(getAngle(m_targetX, m_targetY));
  double v = m_driveTrain->m_turnPID.calculate(m_driveTrain->getBotDirection());
  m_driveTrain->tankDrive(v, -v);
}

// Called once the command ends or is interrupted.
void TurnToPoint::End(bool interrupted) {
  m_driveTrain->arcadeDrive(0, 0);
}

// Returns true when the command should end.
bool TurnToPoint::IsFinished() { 
  return std::abs(m_driveTrain->m_turnPID.calculate(m_driveTrain->getBotDirection())) < 0.05;
}

double TurnToPoint::getAngle(double x, double y) {
  double angle;
  if(x == 0 && y == 0) {
    angle = 0;
  } else {
    angle = std::atan(x / y);
  }
  if(y < 0 && x >= 0){
    angle += M_PI;
  } else if(y < 0 && x < 0){
    angle += M_PI;
    angle = -angle;
  }
  if(m_shooterFront == constant::INTAKE_FORWARD) {
    angle -= M_PI;
  }
  while(angle < -M_PI) {
    angle += 2 * M_PI;
  }
  while(angle > M_PI) {
    angle -= 2 * M_PI;
  }
  return angle;
}
