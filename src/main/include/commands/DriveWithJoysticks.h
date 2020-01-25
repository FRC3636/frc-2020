#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <Robot.h>

#include "subsystems/DriveTrain.h"

class DriveWithJoysticks : public frc2::CommandHelper<frc2::CommandBase, DriveWithJoysticks> {
 public:
  explicit DriveWithJoysticks(DriveTrain* driveTrain, std::function<double()> forward, std::function<double()> turn);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  DriveTrain* m_driveTrain;
  std::function<double()> m_forward;
  std::function<double()> m_turn;
};
