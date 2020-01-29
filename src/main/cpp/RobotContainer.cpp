#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_auto(&m_driveTrain) {
  // Initialize all of your commands and subsystems here
  m_driveTrain.SetDefaultCommand(DriveWithJoysticks(
    &m_driveTrain,
    [this] { return -m_leftJoystick.GetY(); },
    [this] { return m_rightJoystick.GetX(); }));

  // Configure the button bindings
  ConfigureButtonBindings(); 
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  //m_raiseElevatorButton.WhenPressed(RaiseElevator(m_climb));

  //m_lowerElevatorButton.WhenPressed(LowerElevator(m_climb));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return &m_auto;
}
