#pragma once

#include <frc2/command/Command.h>

#include "Constants.h"
#include "commands/DriveWithJoysticks.h"
#include "commands/Auto.h"
#include "subsystems/DriveTrain.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // subsytems
  DriveTrain m_driveTrain;

  // commands
  DriveWithJoysticks m_driveWithJoysticksCommand;
  Auto m_autonomousCommand;

  void ConfigureButtonBindings();
};
