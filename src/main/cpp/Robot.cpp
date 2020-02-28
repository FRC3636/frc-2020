#include "Robot.h"

void Robot::RobotInit() {}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {
  m_container.Reset();
}

void Robot::AutonomousInit() {
  m_container.Reset();
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
  
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
  frc::CameraServer::GetInstance()->StartAutomaticCapture();
  cs::CvSink cvSink = frc::CameraServer::GetInstance()->GetVideo();
  cs::CvSource outputStream = frc::CameraServer::GetInstance()->PutVideo("Camera", 640, 480);
}

void Robot::TeleopPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
