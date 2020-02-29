#include "commands/LeftAuto.h"

LeftAuto::LeftAuto(DriveTrain* driveTrain, NetworkTableHandler* handler) {
  AddCommands(
    TurnWithCamera(driveTrain, handler)
  );
  
}
