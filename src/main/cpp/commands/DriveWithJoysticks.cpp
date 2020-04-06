#include "commands/DriveWithJoysticks.h"

DriveWithJoysticks::DriveWithJoysticks(DriveTrain* driveTrain, Intake* intake, std::function<double()> forward, std::function<double()> turn) : m_driveTrain{driveTrain}, m_intake{intake}, m_forward{forward}, m_turn{turn} {
    AddRequirements({m_driveTrain, m_intake});   
}

void DriveWithJoysticks::Initialize() {
    m_driveTrain->arcadeDrive(0, 0);
}

void DriveWithJoysticks::Execute() {
    m_driveTrain->arcadeDrive(m_forward(), m_turn());
}

void DriveWithJoysticks::End(bool interrupted) {
    m_driveTrain->arcadeDrive(0, 0);
}

bool DriveWithJoysticks::IsFinished() {
    return false;
}