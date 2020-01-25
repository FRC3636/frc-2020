#include "commands/DriveWithJoysticks.h"

DriveWithJoysticks::DriveWithJoysticks(DriveTrain* driveTrain, std::function<double()> forward, std::function<double()> turn)
 : m_driveTrain{driveTrain}, m_forward{forward}, m_turn{turn} {
    AddRequirements({driveTrain});   
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