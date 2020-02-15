#include "commands/LeftAuto.h"
#include "commands/TurnWithCamera.h"

LeftAuto::LeftAuto(DriveTrain* driveTrain, NetworkTableHandler* handler) {
  AddCommands(
    TurnWithCamera(driveTrain, handler),
    DriveToPoint(driveTrain, handler)
  );
  
}
