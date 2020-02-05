#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>

#include "Constants.h"
#include "commands/DriveWithJoysticks.h"
#include "commands/Auto.h"
#include "commands/RaiseElevator.h"
#include "commands/LowerElevator.h"
#include "subsystems/DriveTrain.h"
#include "subsystems/ControlPanelHandler.h"
#include "subsystems/Climb.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  void Reset();

 private:
  // input
  frc::Joystick m_leftJoystick{constant::LEFT_JOYSTICK_PORT};
  frc::Joystick m_rightJoystick{constant::RIGHT_JOYSTICK_PORT};
  frc::XboxController m_controller{constant::CONTROLLER_PORT};

  frc2::JoystickButton m_raiseElevatorButton{&m_leftJoystick, 3};
  frc2::JoystickButton m_lowerElevatorButton{&m_rightJoystick, 3};

  // subsytems
  DriveTrain m_driveTrain;
  ControlPanelHandler m_controlPanelHandler;
  Climb m_climb;

  // commands
  Auto m_auto{&m_driveTrain};

  void ConfigureButtonBindings();
};
