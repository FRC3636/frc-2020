#include "commands/TurnWithCamera.h"

TurnWithCamera::TurnWithCamera(DriveTrain* driveTrain, NetworkTableHandler* network) : m_driveTrain{driveTrain}, m_network{network} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({driveTrain, network});
}

void TurnWithCamera::Initialize() {
  m_driveTrain->m_turnPID.setSetPoint(MIDDLE_OF_FRAME);
  m_driveTrain->tankDrive(0, 0);
}

void TurnWithCamera::Execute() {
  std::cout << "recieved angle: " << m_network->getAngle() << std::endl;
  if(m_network->getAngle() > 0) {
    std::cout << "over 0" << std::endl;
  }
  double v = m_driveTrain->m_turnPID.calculate(m_network->getAngle());
  m_driveTrain->tankDrive(v, -v);
}

void TurnWithCamera::End(bool interrupted) {
  m_driveTrain->tankDrive(0, 0);
}

bool TurnWithCamera::IsFinished() {
  return false;
  //return std::abs(m_driveTrain->m_turnPID.calculate(m_network->getAngle())) < 0.05;
}