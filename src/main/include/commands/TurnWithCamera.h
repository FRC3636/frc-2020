#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrain.h"
#include "subsystems/NetworkTableHandler.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TurnWithCamera : public frc2::CommandHelper<frc2::CommandBase, TurnWithCamera> {
 public:
  TurnWithCamera(DriveTrain* driveTrain, NetworkTableHandler* m_network);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 private:
  DriveTrain* m_driveTrain;
  NetworkTableHandler* m_network;

  static constexpr double MIDDLE_OF_FRAME = 45.0;
};
