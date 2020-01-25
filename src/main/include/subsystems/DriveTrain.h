#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/VictorSP.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Encoder.h>
#include <rev/ColorSensorV3.h>
#include "Constants.h"

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();

  void arcadeDrive(float forward, float turn);

  void tankDrive(float leftMotor, float rightMotor);

  void resetEncoders();

  double getLeftEncoderValue();
  double getRightEncoderValue();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::VictorSP m_leftMotor{constant::LEFT_MOTOR_PORT};
  frc::VictorSP m_rightMotor{constant::RIGHT_MOTOR_PORT};
  frc::DifferentialDrive m_myRobot{m_leftMotor, m_rightMotor};

  frc::Encoder m_leftEncoder{constant::LEFT_ENCODER_PORT_1, constant::LEFT_ENCODER_PORT_2, false, frc::Encoder::EncodingType::k4X};
  frc::Encoder m_rightEncoder{constant::RIGHT_ENCODER_PORT_1, constant::RIGHT_ENCODER_PORT_2, false, frc::Encoder::EncodingType::k4X};
};
