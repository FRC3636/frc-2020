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
#include "commands/IntakeCells.h"
#include "commands/OuttakeCells.h"
#include "commands/ConveyCells.h"
#include "subsystems/DriveTrain.h"
#include "subsystems/ControlPanelHandler.h"
#include "subsystems/Climb.h"
#include "subsystems/NetworkTableHandler.h"
#include "subsystems/Shooter.h"
#include "subsystems/Intake.h"
#include "subsystems/Conveyor.h"

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

  // ########## REVIEW ##########
  // Buttons to control the intake and the conveyor
  // I tried to keep the same button as before
  frc2::JoystickButton m_intakeButton{&m_controller, (int)frc::XboxController::Button::kBumperLeft};
  frc2::JoystickButton m_intakeReverseButton{&m_controller, (int)frc::XboxController::Button::kY};
  frc2::JoystickButton m_conveyorButton{&m_rightJoystick, 1}; // Trigger button = button 1

  // subsytems
  DriveTrain m_driveTrain;
  ControlPanelHandler m_controlPanelHandler;
  Climb m_climb;
  NetworkTableHandler m_handler;
  Shooter m_shooter;
  Intake m_intake;
  Conveyor m_conveyor;

  // commands
  Auto m_auto{&m_driveTrain, &m_shooter, &m_intake};
  LeftAuto m_leftAuto{&m_driveTrain, &m_handler};

  frc::SendableChooser<frc2::Command*> m_chooser;

  void ConfigureButtonBindings();
  double getIntake();
};
