/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Climb.h"

Climb::Climb() {}

void Climb::setMotor(double speed) {
    m_elevatorMotor.Set(speed);
}

void Climb::setBrakeMotor(double speed) {
    m_brakeMotor.Set(speed);
}

bool Climb::getLowerLimitSwitch() {
    return m_lowerLimitSwitch.Get();
}

bool Climb::getUpperLimitSwitch() {
    return m_upperLimitSwitch.Get();
}
