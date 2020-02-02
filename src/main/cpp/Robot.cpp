#include "Robot.h"

void Robot::RobotInit() {
  m_container.Reset();
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {
  m_container.Reset();
}

void Robot::DisabledPeriodic() {
  std::cout << "disabled" << std::endl;
  m_container.Reset();
  m_container.UpdateDriveTrain();
}

void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

void Robot::TeleopInit() {
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
}

void Robot::TeleopPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
