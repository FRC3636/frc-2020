#pragma once

#include <frc2/command/SubsystemBase.h>

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();


  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
