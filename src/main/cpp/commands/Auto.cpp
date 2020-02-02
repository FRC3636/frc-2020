#include "commands/Auto.h"

Auto::Auto(DriveTrain* driveTrain) {
  AddCommands(
    //add auto commands here
    TurnToPoint(driveTrain, constant::LIST_OF_POINTS[0].first, constant::LIST_OF_POINTS[0].second),
    DriveToPoint(driveTrain, constant::LIST_OF_POINTS[0].first, constant::LIST_OF_POINTS[0].second)
  );
}
