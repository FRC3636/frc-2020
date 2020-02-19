#pragma once

#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/EntryListenerFlags.h>
#include <iostream>

class NetworkTableHandler : public frc2::SubsystemBase {
 public:
  NetworkTableHandler();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  double getAngle();
  double getDistance();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  nt::NetworkTableInstance m_inst = nt::NetworkTableInstance::GetDefault();
  std::shared_ptr<nt::NetworkTable> m_table = m_inst.GetTable("SmartDashboard");
  nt::NetworkTableEntry m_Angle = m_table->GetEntry("Angle");
  nt::NetworkTableEntry m_Distance = m_table->GetEntry("Distance");
};
