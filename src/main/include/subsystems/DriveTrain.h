#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Spark.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/Encoder.h>
#include <frc/AnalogGyro.h>
#include "Constants.h"
#include "controlLib/SynchronousPID.h"

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();

  void Periodic() override;

  void updateOdometry();

  void arcadeDrive(float forward, float turn);

  void tankDrive(float leftMotor, float rightMotor);

  void resetEncoders();

  double getLeftEncoderValue();
  double getRightEncoderValue();

  double getBotDirection();
  double getBotDistance();
  double getX();
  double getY();

  void resetDistance();

  SynchronousPID m_turnPID{0.15, 15, 0.0015, 0, 0, -0.6, 0.6};
  SynchronousPID m_drivePID{0.085/88, 0.024, 0.38/6.0, 0, 0, -0.6, 0.6};
  SynchronousPID m_percentageTurnPID{1, 0, 0, 0, 0, 0.5, -0.5};

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Spark m_leftMotor{constant::LEFT_MOTOR_PORT};
  frc::Spark m_rightMotor{constant::RIGHT_MOTOR_PORT};
  frc::DifferentialDrive m_myRobot{m_leftMotor, m_rightMotor};

  frc::AnalogGyro m_imu{constant::I2C_PORT};

  frc::Encoder m_leftEncoder{constant::LEFT_ENCODER_PORT_1, constant::LEFT_ENCODER_PORT_2, false, frc::Encoder::EncodingType::k4X};
  frc::Encoder m_rightEncoder{constant::RIGHT_ENCODER_PORT_1, constant::RIGHT_ENCODER_PORT_2, false, frc::Encoder::EncodingType::k4X};

  double m_oldTR = 0.0;
  double m_oldTL = 0.0;
  double m_velocity = 0;
  double m_botDistance = 0.0;
  double m_botDirection = 0.0;
  double m_botX = 0.0;
  double m_botY = 0.0;
};
