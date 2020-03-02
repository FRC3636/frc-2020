#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Set up auto
  m_chooser.AddOption("Auto", &m_auto);
  m_chooser.AddOption("Left Auto", &m_leftAuto);

  frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);
  // Initialize all of your commands and subsystems here
  m_driveTrain.SetDefaultCommand(DriveWithJoysticks(
    &m_driveTrain,
    &m_intake,
    [this] { return -m_leftJoystick.GetY(); },
    [this] { return m_rightJoystick.GetX(); },
    [this] { return m_leftJoystick.GetTrigger(); }
  ));

  // Configure the button bindings
  ConfigureButtonBindings(); 
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  m_raiseElevatorButton.WhenPressed(RaiseElevator(
    &m_climb,
    [this] { return -(m_leftJoystick.GetZ() - 1) / 2.0; },
    [this] { return m_leftJoystick.GetRawButton(8); }
  ));

  m_lowerElevatorButton.WhenPressed(LowerElevator(
    &m_climb,
    [this] { return (m_rightJoystick.GetZ() - 1) / 2.0; },
    [this] { return m_rightJoystick.GetRawButton(8); }
  ));

  m_brakeButton.WhenPressed(SetBrake(
    &m_climb
  ));

  m_shooterButton.WhenPressed(ShootBalls(
    &m_shooter,
    [this] { return m_rightJoystick.GetRawButton(3); },
    [this] { return m_rightJoystick.GetTriggerReleased(); }
  ));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_chooser.GetSelected();
}

void RobotContainer::Reset() {
  m_driveTrain.resetEncoders();
}