#include "commands/Auto.h"

Auto::Auto() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void Auto::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Auto::Execute() {}

// Called once the command ends or is interrupted.
void Auto::End(bool interrupted) {}

// Returns true when the command should end.
bool Auto::IsFinished() { return false; }
