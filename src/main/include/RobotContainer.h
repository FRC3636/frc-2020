#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <iostream>

#include "Constants.h"
#include "commands/DriveWithJoysticks.h"
#include "commands/Auto.h"
#include "commands/LeftAuto.h"
#include "commands/RaiseElevator.h"
#include "commands/LowerElevator.h"
#include "commands/SetBrake.h"
#include "commands/ShootBalls.h"
#include "commands/ShootWithPreset.h"
#include "subsystems/DriveTrain.h"
#include "subsystems/ControlPanelHandler.h"
#include "subsystems/Climb.h"
#include "subsystems/NetworkTableHandler.h"
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  void Reset();

  void outputCameraData();

 private:
  // input
  frc::Joystick m_leftJoystick{constant::LEFT_JOYSTICK_PORT};
  frc::Joystick m_rightJoystick{constant::RIGHT_JOYSTICK_PORT};
  frc::XboxController m_controller{constant::CONTROLLER_PORT};

  frc2::JoystickButton m_raiseElevatorButton{&m_controller, (int)frc::XboxController::Button::kStickRight};
  frc2::JoystickButton m_brakeButton{&m_controller, (int)frc::XboxController::Button::kStart};
  frc2::JoystickButton m_brakeOffButton{&m_controller, (int)frc::XboxController::Button::kBack};
  frc2::JoystickButton m_shooterButton{&m_controller, (int)frc::XboxController::Button::kBumperRight};
  frc2::JoystickButton m_shooterPresetMid{&m_controller, (int)frc::XboxController::Button::kA};
  frc2::JoystickButton m_shooterPresetFar{&m_controller, (int)frc::XboxController::Button::kB};
  frc2::JoystickButton m_shooterPresetHigh{&m_controller, (int)frc::XboxController::Button::kX};

  // subsytems
  DriveTrain m_driveTrain;
  ControlPanelHandler m_controlPanelHandler;
  Climb m_climb;
  NetworkTableHandler m_handler;
  Shooter m_shooter;
  Intake m_intake;

  // commands
  Auto m_auto{&m_driveTrain, &m_shooter, &m_intake};
  LeftAuto m_leftAuto{&m_driveTrain, &m_handler};

  frc::SendableChooser<frc2::Command*> m_chooser;

  void ConfigureButtonBindings();
  double getIntake();
};
