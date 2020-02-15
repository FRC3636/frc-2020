#include "commands/DriveWithCamera.h"

DriveWithCamera::DriveWithCamera(DriveTrain* driveTrain, NetworkTableHandler* network) : m_driveTrain{driveTrain}, m_network{network} {
  // Use addRequirements() here to declare system dependencies.
  AddRequirements({driveTrain, network});
}

void TurnWithCamera::Initialize() {
  m_driveTrain->m_drivePID.setSetPoint(BOT_POSITION);
  m_driveTrain->tankDrive(0, 0);
}

void TurnWithCamera::Execute() {
  double v = m_driveTrain->m_drivePID.calculate(m_network->getDistance());
  m_driveTrain->tankDrive(v, v);
}

void TurnWithCamera::End(bool interrupted) {
  m_driveTrain->tankDrive(0, 0);
}

bool TurnWithCamera::IsFinished() {
  return std::abs(m_driveTrain->m_drivePID.calculate(m_network->getDistance())) < 0.05;
}
