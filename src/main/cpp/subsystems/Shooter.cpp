/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"

Shooter::Shooter() {}

// This method will be called once per scheduler run
void Shooter::setShooter(bool shooting) {
    if(shooting) {
        m_leftShooterMotor.Set(1);
        m_rightShooterMotor.Set(-1);
    } else {
        m_leftShooterMotor.Set(0);
        m_rightShooterMotor.Set(0);
    }
}
