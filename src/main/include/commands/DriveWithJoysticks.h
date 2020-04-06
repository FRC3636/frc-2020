#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrain.h"
#include "subsystems/Intake.h"

// ########## REVIEW ##########
// DriveWithJoystick shouldn't control the intake, this should be done in a separate command -> IntakeCells
// Because I divided the Intake in two move balls is in the ConveyCells command

class DriveWithJoysticks : public frc2::CommandHelper<frc2::CommandBase, DriveWithJoysticks> {
 public:
  explicit DriveWithJoysticks(DriveTrain* driveTrain, Intake* intake, std::function<double()> forward, std::function<double()> turn);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  DriveTrain* m_driveTrain;
  Intake* m_intake;
  std::function<double()> m_forward;
  std::function<double()> m_turn;
};
