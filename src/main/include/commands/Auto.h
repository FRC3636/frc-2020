#pragma once

#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveTrain.h"
#include "commands/TurnToPoint.h"
#include "commands/DriveToPoint.h"

class Auto : public frc2::CommandHelper<frc2::SequentialCommandGroup, Auto> {
 public:
  Auto(DriveTrain* driveTrain);

};
