/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "controlLib/Odometry.h"

Odometry::Odometry(const double widthBetweenWheels, const std::pair<int, int> leftEncoderPorts, const std::pair<int, int> rightEncoderPorts) : WIDTH_BETWEEN_WHEELS(widthBetweenWheels), m_leftEncoder{leftEncoderPorts.first, leftEncoderPorts.second, false, frc::Encoder::EncodingType::k4X}, m_rightEncoder{rightEncoderPorts.first, rightEncoderPorts.second, false, frc::Encoder::EncodingType::k4X} {}

void Odometry::updateOdometry() {
  double tR = -m_rightEncoder.Get() - m_oldTR;
  double tL = m_leftEncoder.Get() - m_oldTL;

  double dTheta = ((tR - tL)*0.0184)/(WIDTH_BETWEEN_WHEELS);
  m_botDirection += dTheta;

  double dAV = ((tR + tL)*0.0184*2.54)/2.0;
  m_botDistance += dAV;

  m_velocity = dAV * 50.0;

  double dY = dAV * std::cos(m_botDirection);
  m_botY += dY;

  double dX = dAV * std::sin(m_botDirection);
  m_botX += dX;

  m_oldTR = -m_rightEncoder.Get();
  m_oldTL = m_leftEncoder.Get();
}

void Odometry::resetEncoders() {
  m_rightEncoder.Reset();
  m_rightEncoder.SetSamplesToAverage(5);
  m_rightEncoder.SetMaxPeriod(10);
  m_rightEncoder.SetDistancePerPulse(1);

  m_leftEncoder.Reset();
  m_leftEncoder.SetSamplesToAverage(5);
  m_leftEncoder.SetMaxPeriod(10);
  m_leftEncoder.SetDistancePerPulse(1);

  m_oldTR = 0.0;
  m_oldTL = 0.0;
  m_velocity = 0;
  m_botDistance = 0.0;
  m_botDirection = 0.0;
  m_botX = 0.0;
  m_botY = 0.0;
}

double Odometry::getLeftEncoderValue() {
    return m_leftEncoder.Get();
}

double Odometry::getRightEncoderValue() {
    return m_rightEncoder.Get();
}

double Odometry::getBotDirection() {
  return m_botDirection;
}

double Odometry::getBotDistance() {
  return m_botDistance;
}

double Odometry::getX() {
  return m_botX;
}

double Odometry::getY() {
  return m_botY;
}

void Odometry::resetDistance() {
  m_botDistance = 0;
}
