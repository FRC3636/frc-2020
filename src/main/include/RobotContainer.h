#pragma once

#include <frc2/command/Command.h>

#include "commands/DriveWithJoysticks.h"
#include "subsystems/DriveTrain.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  DriveTrain m_driveTrain;
  DriveWithJoysticks m_autonomousCommand;

  void ConfigureButtonBindings();
};
