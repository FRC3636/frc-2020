#include "commands/Auto.h"

Auto::Auto(DriveTrain* driveTrain, Shooter* shooter, Intake* intake) {
  AddCommands(
    //add auto commands here
    //TurnToPoint(driveTrain, 0, -50),
    DriveToPoint(driveTrain, 0, 20),
    ShootInAuto(intake, shooter)
    //set power to .555118
  );
}
