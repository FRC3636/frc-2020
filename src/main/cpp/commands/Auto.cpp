#include "commands/Auto.h"

Auto::Auto(DriveTrain* driveTrain, Shooter* shooter, Intake* intake) {
  AddCommands(
    //add auto commands here
    //TurnToPoint(driveTrain, 0, -50),
    DriveToPoint(driveTrain, 0, 20)
    //set power to .555118
  );
  shooter->setShooter(0.555118);
  intake->setLowerShooter(true);
}
