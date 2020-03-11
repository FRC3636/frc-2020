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
class DriveToPoint : public frc2::CommandHelper<frc2::CommandBase, DriveToPoint> {
 public:
  DriveToPoint(DriveTrain* driveTrain, double x, double y, int flipped);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  double getDistance(double x, double y);
 private:
  DriveTrain* m_driveTrain;
  double m_targetX;
  double m_targetY;
  int m_flipped;
};
