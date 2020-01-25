#pragma once

#include <frc2/command/Command.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/shuffleboard/Shuffleboard.h>

#include "Constants.h"
#include "commands/DriveWithJoysticks.h"
#include "commands/Auto.h"
#include "subsystems/DriveTrain.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // input
  frc::Joystick m_leftJoystick{constant::LEFT_JOYSTICK_PORT};
  frc::Joystick m_rightJoystick{constant::RIGHT_JOYSTICK_PORT};
  frc::XboxController m_controller{constant::CONTROLLER_PORT};

  // subsytems
  DriveTrain m_driveTrain;

  // commands
  Auto m_auto{&m_driveTrain};

  // choose auto
  frc::SendableChooser<frc2::Command*> m_chooser;

  void ConfigureButtonBindings();
};
