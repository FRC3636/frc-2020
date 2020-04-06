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
    [this] { return m_rightJoystick.GetX(); }
  ));

  // Configure the button bindings
  ConfigureButtonBindings(); 
}

void RobotContainer::outputCameraData() {
  std::cout << "Angle: " << m_handler.getAngle() << ", Distance: " << m_handler.getDistance() << std::endl;
}

void RobotContainer::ConfigureButtonBindings() {
  // ########## REVIEW ##########
  // Because intaking and conveying is no longer in DriveWithJoystick, we have to assign a button to it
  // WhileActiveContinous permit to "Binds a command to be started repeatedly while the
  // trigger is active, and cancelled when it becomes inactive". That's what we want !!!
  //
  // These frc2::JoystickButton replace your getIntake() function
  m_intakeButton.WhileActiveContinous(IntakeCells(&m_intake));
  m_intakeReverseButton.WhileActiveContinous(OuttakeCells(&m_intake));
  m_conveyorButton.WhileActiveContinous(ConveyCells(&m_conveyor));

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
    [this] { return m_controller.GetRawButtonReleased((int)frc::XboxController::Button::kX); }
  ));

  m_shooterPresetMid.WhenPressed(ShootWithPreset(
    &m_shooter,
    constant::MID_MOTOR_POWER,
    [this] { return m_controller.GetRawButtonReleased((int)frc::XboxController::Button::kA); }
  ));

  m_shooterPresetFar.WhenPressed(ShootWithPreset(
    &m_shooter,
    constant::FAR_MOTOR_POWER,
    [this] { return m_controller.GetRawButtonReleased((int)frc::XboxController::Button::kB); }
  ));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_chooser.GetSelected();
}

void RobotContainer::Reset() {
  m_driveTrain.resetEncoders();
}
