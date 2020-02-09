/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

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
  double getX();
  double getY();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  nt::NetworkTableInstance m_inst = nt::NetworkTableInstance::GetDefault();
  std::shared_ptr<nt::NetworkTable> m_table = m_inst.GetTable("SmartDashboard");
  nt::NetworkTableEntry m_X = m_table->GetEntry("X");
  nt::NetworkTableEntry m_Y = m_table->GetEntry("Y");
};
