#include "commands/Auto.h"

Auto::Auto(DriveTrain* driveTrain) {
  AddCommands(
    //add auto commands here
    TurnToPoint(driveTrain, 0, 60*2.54),
    DriveToPoint(driveTrain, 0, 60*2.54)
  );
}
