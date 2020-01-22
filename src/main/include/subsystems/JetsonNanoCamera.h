/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>

class JetsonNanoCamera : public frc2::SubsystemBase {
   public:
    explicit JetsonNanoCamera();
    double GetSpinError();
    bool GetIsHaveTarget();

   private:
    nt::NetworkTableEntry m_isHaveTarget;
    nt::NetworkTableEntry m_spinError;
};
