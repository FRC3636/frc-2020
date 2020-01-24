#include "commands/DriveWithJoysticks.h"

DriveWithJoysticks::DriveWithJoysticks(DriveTrain* driveTrain) : m_driveTrain{driveTrain} {
    AddRequirements({m_driveTrain});   
}

void DriveWithJoysticks::Initialize() {
    m_driveTrain->ArcadeDrive(0, 0);
}

void DriveWithJoysticks::Execute() {

}

void DriveWithJoysticks::End(bool interrupted) {
    m_driveTrain->ArcadeDrive(0, 0);
}

bool DriveWithJoysticks::IsFinished() {
    return false;
}