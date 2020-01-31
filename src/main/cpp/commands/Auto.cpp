#include "commands/Auto.h"

Auto::Auto(DriveTrain* driveTrain) {
  //bad and allocating a bunch of stack objects. will discuss how to fix this temp code (that allows you go to multiple points) in class
  AddCommands(
    //add auto commands here
    TurnToPoint(driveTrain, constant::LIST_OF_POINTS[0].first, constant::LIST_OF_POINTS[0].second),
    DriveToPoint(driveTrain, constant::LIST_OF_POINTS[0].first, constant::LIST_OF_POINTS[0].second)
  );
}
