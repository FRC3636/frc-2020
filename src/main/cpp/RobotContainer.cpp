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
    true,
    [this] { return m_controller.GetRawButtonReleased((int)frc::XboxController::Button::kStart); }
  ));

  m_brakeOffButton.WhenPressed(SetBrake(
    &m_climb,
    false,
    [this] { return m_controller.GetRawButtonReleased((int)frc::XboxController::Button::kBack); }
  ));

  m_shooterButton.WhenPressed(ShootBalls(
    &m_shooter,
    [this] { return -(m_rightJoystick.GetZ() - 3) / 4.0; },
    [this] { return m_controller.GetRawButtonReleased((int)frc::XboxController::Button::kBumperRight); }
  ));

  m_shooterPresetHigh.WhenPressed(ShootWithPreset(
    &m_shooter,
    constant::HIGH_MOTOR_POWER,
    [this] { return m_controller.GetRawButtonReleased((int)frc::XboxController::Button::kB); }
  ));

  m_shooterPresetMid.WhenPressed(ShootWithPreset(
    &m_shooter,
    constant::MID_MOTOR_POWER,
    [this] { return m_controller.GetRawButtonReleased((int)frc::XboxController::Button::kA); }
  ));

  m_shooterPresetLow.WhenPressed(ShootWithPreset(
    &m_shooter,
    constant::LOW_MOTOR_POWER,
    [this] { return m_controller.GetRawButtonReleased((int)frc::XboxController::Button::kX); }
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
