#pragma once

#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveTrain.h"
#include "subsystems/NetworkTableHandler.h"
#include "commands/TurnToPoint.h"
#include "commands/DriveToPoint.h"
#include "commands/TurnToLemon.h"
#include "Constants.h"

class LeftAuto : public frc2::CommandHelper<frc2::SequentialCommandGroup, LeftAuto> {
 public:
  LeftAuto(DriveTrain* driveTrain, NetworkTableHandler* handler);
};
