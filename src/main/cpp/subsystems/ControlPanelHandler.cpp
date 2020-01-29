/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ControlPanelHandler.h"
#include <iostream>

ControlPanelHandler::ControlPanelHandler() {
    m_colorMatcher.AddColorMatch(constant::YELLOW);
    m_colorMatcher.AddColorMatch(constant::RED);
    m_colorMatcher.AddColorMatch(constant::GREEN);
    m_colorMatcher.AddColorMatch(constant::BLUE);
}

// This method will be called once per scheduler run
void ControlPanelHandler::Periodic() {
    std::string colorString;
    double confidence = 0.0;
    frc::Color matchedColor = m_colorMatcher.MatchClosestColor(m_colorSensor.GetColor(), confidence);

    if (matchedColor == constant::BLUE) {
      colorString = "Blue";
    } else if (matchedColor == constant::RED) {
      colorString = "Red";
    } else if (matchedColor == constant::GREEN) {
      colorString = "Green";
    } else if (matchedColor == constant::YELLOW) {
      colorString = "Yellow";
    } else {
      colorString = "Unknown";
    }

    std::cout << "Color: " << colorString << " Confidence: " << confidence << std::endl;
}