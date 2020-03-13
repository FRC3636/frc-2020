/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/Encoder.h>

class Odometry {
 public:
  Odometry(const double widthBetweenWheels, const std::pair<int, int> leftEncoderPorts, const std::pair<int, int> rightEncoderPorts);

  void updateOdometry();

  void resetEncoders();
  double getLeftEncoderValue();
  double getRightEncoderValue();

  double getBotDirection();
  double getBotDistance();
  double getX();
  double getY();

  void resetDistance();

private:
  frc::Encoder m_leftEncoder;
  frc::Encoder m_rightEncoder;
  const double WIDTH_BETWEEN_WHEELS;

  double m_oldTR = 0.0;
  double m_oldTL = 0.0;
  double m_velocity = 0;
  double m_botDistance = 0.0;
  double m_botDirection = 0.0;
  double m_botX = 0.0;
  double m_botY = 0.0;
};
