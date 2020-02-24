#include "commands/DriveWithJoysticks.h"

DriveWithJoysticks::DriveWithJoysticks(DriveTrain* driveTrain, Intake* intake, std::function<double()> forward, std::function<double()> turn, std::function<double()> shouldIntake, std::function<bool()> shouldMoveBalls) : m_driveTrain{driveTrain}, m_intake{intake}, m_forward{forward}, m_turn{turn}, m_shouldIntake{shouldIntake}, m_shouldMoveBalls{shouldMoveBalls} {
    AddRequirements({m_driveTrain, m_intake});   
}

void DriveWithJoysticks::Initialize() {
    m_driveTrain->arcadeDrive(0, 0);
    m_intake->setIntake(0);
    m_intake->setLowerShooter(false);
}

void DriveWithJoysticks::Execute() {
    m_driveTrain->arcadeDrive(m_forward(), m_turn());
    m_intake->setIntake(m_shouldIntake());
    m_intake->setLowerShooter(m_shouldMoveBalls());
}

void DriveWithJoysticks::End(bool interrupted) {
    m_driveTrain->arcadeDrive(0, 0);
    m_intake->setIntake(0);
    m_intake->setLowerShooter(false);
}

bool DriveWithJoysticks::IsFinished() {
    return false;
}