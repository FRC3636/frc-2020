#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Spark.h>
#include <frc/drive/DifferentialDrive.h>
#include "Constants.h"
#include "controlLib/SynchronousPID.h"
#include "controlLib/Odometry.h"

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();

  void Periodic() override;

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

  SynchronousPID m_turnPID{3.0, 0.0, 0.0, 0, 0.03, -0.8, 0.8};
  SynchronousPID m_drivePID{0.55, 0.0, 3.0, 0, 0.5, -0.6, 0.6};
  SynchronousPID m_percentageTurnPID{1, 0, 0, 0, 0, 0.5, -0.5};

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Spark m_leftMotor{constant::LEFT_MOTOR_PORT};
  frc::Spark m_rightMotor{constant::RIGHT_MOTOR_PORT};
  frc::DifferentialDrive m_myRobot{m_leftMotor, m_rightMotor};

  Odometry m_odometryHandler{constant::WIDTH_BETWEEN_WHEELS, constant::LEFT_ENCODER_PORTS, constant::RIGHT_ENCODER_PORTS};
};
