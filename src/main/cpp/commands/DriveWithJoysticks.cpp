#include "commands/DriveWithJoysticks.h"

DriveWithJoysticks::DriveWithJoysticks(DriveTrain* driveTrain, std::function<double()> forward, std::function<double()> turn)
 : m_driveTrain{driveTrain}, m_forward{forward}, m_turn{turn} {
    AddRequirements({driveTrain});   
}

void DriveWithJoysticks::Initialize() {
    m_driveTrain->ArcadeDrive(0, 0);
}

void DriveWithJoysticks::Execute() {
    m_driveTrain->ArcadeDrive(m_forward(), m_turn());
}

void DriveWithJoysticks::End(bool interrupted) {
    m_driveTrain->ArcadeDrive(0, 0);
}

bool DriveWithJoysticks::IsFinished() {
    return false;
}