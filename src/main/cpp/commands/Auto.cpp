#include "commands/Auto.h"

Auto::Auto(DriveTrain* driveTrain, Shooter* shooter, Intake* intake) {
  AddCommands(
    DriveToPoint(driveTrain, 0, 100, constant::SHOOTER_FORWARD),
    TurnToPoint(driveTrain, 100, 100, constant::SHOOTER_FORWARD),
    DriveToPoint(driveTrain, 100, 100, constant::SHOOTER_FORWARD),
    TurnToPoint(driveTrain, 100, 0, constant::SHOOTER_FORWARD),
    DriveToPoint(driveTrain, 100, 0, constant::SHOOTER_FORWARD),
    TurnToPoint(driveTrain, 0, 0, constant::SHOOTER_FORWARD),
    DriveToPoint(driveTrain, 0, 0, constant::SHOOTER_FORWARD),
    TurnToPoint(driveTrain, 0, 100, constant::SHOOTER_FORWARD)
  );
}
