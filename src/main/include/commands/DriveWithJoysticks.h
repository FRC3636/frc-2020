#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrain.h"
#include "subsystems/Intake.h"

class DriveWithJoysticks : public frc2::CommandHelper<frc2::CommandBase, DriveWithJoysticks> {
 public:
  explicit DriveWithJoysticks(DriveTrain* driveTrain, Intake* intake, std::function<double()> forward, std::function<double()> turn, std::function<bool()> shouldIntake, std::function<bool()> shouldMoveBalls);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  DriveTrain* m_driveTrain;
  Intake* m_intake;
  std::function<double()> m_forward;
  std::function<double()> m_turn;
  std::function<bool()> m_shouldIntake;
  std::function<bool()> m_shouldMoveBalls;
};
