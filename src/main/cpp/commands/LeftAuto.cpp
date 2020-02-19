#include "commands/LeftAuto.h"
#include "commands/TurnWithCamera.h"

LeftAuto::LeftAuto(DriveTrain* driveTrain, NetworkTableHandler* handler) {
  AddCommands(
    TurnWithCamera(driveTrain, handler),
    DriveWithCamera(driveTrain, handler)
  );
  
}
