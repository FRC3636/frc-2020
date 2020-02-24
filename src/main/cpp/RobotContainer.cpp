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
    [this] { return m_leftJoystick.GetY(); },
    [this] { return m_rightJoystick.GetX(); },
    [this] { return getIntake(); },
    [this] { return m_rightJoystick.GetTrigger(); }
  ));

  // Configure the button bindings
  ConfigureButtonBindings(); 
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  m_raiseElevatorButton.WhenPressed(RaiseElevator(
    &m_climb,
    [this] { return m_controller.GetY(frc::GenericHID::kRightHand); },
    [this] { return m_controller.GetRawButton((int)frc::XboxController::Button::kB); }
  ));

  m_brakeButton.WhenPressed(SetBrake(
    &m_climb,
    true
  ));

  m_brakeOffButton.WhenPressed(SetBrake(
    &m_climb,
    false
  ));

  m_shooterButton.WhenPressed(ShootBalls(
    &m_shooter,
    [this] { return -(m_leftJoystick.GetZ() - 1) / 2.0; },
    [this] { return m_controller.GetRawButtonReleased((int)frc::XboxController::Button::kBumperRight); }
  ));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_chooser.GetSelected();
}

void RobotContainer::Reset() {
  m_driveTrain.resetEncoders();
}

double RobotContainer::getIntake() {
  if(m_controller.GetRawButton((int)frc::XboxController::Button::kBumperLeft)) {
    return 1;
  } else if(m_controller.GetRawButton((int)frc::XboxController::Button::kY)) {
    return -1;
  } else {
    return 0;
  }
}