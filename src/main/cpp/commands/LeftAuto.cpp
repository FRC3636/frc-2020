/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LeftAuto.h"

LeftAuto::LeftAuto(DriveTrain* driveTrain, NetworkTableHandler* handler) {
  AddCommands(
    TurnToPoint(driveTrain, handler->getX(), handler->getY()),
    DriveToPoint(driveTrain, handler->getX(), handler->getY())
  );
  
}
