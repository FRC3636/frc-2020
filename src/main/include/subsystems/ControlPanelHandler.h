/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/ColorSensorV3.h>
#include <rev/ColorMatch.h>

#include "Constants.h"

class ControlPanelHandler : public frc2::SubsystemBase {
 public:
  ControlPanelHandler();

  void Periodic();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::ColorSensorV3 m_colorSensor{constant::I2C_PORT};
  rev::ColorMatch m_colorMatcher;
};
