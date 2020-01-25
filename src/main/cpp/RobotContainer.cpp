#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems her
  m_chooser.AddOption("Auto", &m_auto);

  frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);

  // Configure the button bindings
  ConfigureButtonBindings();

  m_driveTrain.SetDefaultCommand(DriveWithJoysticks(
    &m_driveTrain,
    [this] { return m_leftJoystick.GetY(); },
    [this] { return -m_rightJoystick.GetX(); }));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_chooser.GetSelected();
}
