#include "commands/Auto.h"

Auto::Auto(DriveTrain* driveTrain) {
  AddCommands(
    //add auto commands here
    DriveToPoint(driveTrain, 0, 100)
  );
}
