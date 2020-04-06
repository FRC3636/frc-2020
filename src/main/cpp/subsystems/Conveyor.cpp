/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Conveyor.h"

Conveyor::Conveyor() {}

// This method will be called once per scheduler run
void Conveyor::activateConveyor() {
    m_lowerShooterMotor.Set(1);
}

void Conveyor::stopConveyor() {
    m_lowerShooterMotor.Set(0);
}
