#include "commands/Auto.h"

Auto::Auto(DriveTrain* driveTrain) {
  AddCommands(
    //add auto commands here
    TurnToPoint(driveTrain, 21*2.54, 100*2.54),
    DriveToPoint(driveTrain, 21*2.54, 100*2.54),
    TurnToPoint(driveTrain, constant::LIST_OF_POINTS[1].first, constant::LIST_OF_POINTS[1].second),
    DriveToPoint(driveTrain, constant::LIST_OF_POINTS[1].first, constant::LIST_OF_POINTS[1].second),
    TurnToPoint(driveTrain, constant::LIST_OF_POINTS[2].first, constant::LIST_OF_POINTS[2].second),
    DriveToPoint(driveTrain, constant::LIST_OF_POINTS[2].first, constant::LIST_OF_POINTS[2].second),
    TurnToPoint(driveTrain, constant::LIST_OF_POINTS[3].first, constant::LIST_OF_POINTS[3].second),
    DriveToPoint(driveTrain, constant::LIST_OF_POINTS[3].first, constant::LIST_OF_POINTS[3].second)
  );
}
