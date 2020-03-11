#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrain.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TurnToPoint : public frc2::CommandHelper<frc2::CommandBase, TurnToPoint> {
 public:
  TurnToPoint(DriveTrain* driveTrain, float x, float y, int shooterFront);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 private:
  DriveTrain* m_driveTrain;
  float m_targetX;
  float m_targetY;
  int m_shooterFront;

  double getAngle(double x, double y);
};
