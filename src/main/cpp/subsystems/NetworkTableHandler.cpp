/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/NetworkTableHandler.h"

NetworkTableHandler::NetworkTableHandler() {}

// This method will be called once per scheduler run
double NetworkTableHandler::getX() {
    return m_X.GetDouble(0);
}

double NetworkTableHandler::getY() {
    return m_Y.GetDouble(0);
}
