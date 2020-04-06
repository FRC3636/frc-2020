/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

Intake::Intake() {}

void Intake::activateIntake() {
    m_intakeMotor.Set(1);
}

void Intake::activateIntakeReverse() {
    m_intakeMotor.Set(-1);
}

void Intake::stopIntake() {
    m_intakeMotor.Set(0);
}
