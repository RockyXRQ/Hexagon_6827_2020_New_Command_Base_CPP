/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/JetsonNanoCamera.h"
#include <networktables/NetworkTableInstance.h>

JetsonNanoCamera::JetsonNanoCamera() {
    auto m_networkTable =
        nt::NetworkTableInstance::GetDefault().GetTable("JETSONNANO");
    m_isHaveTarget = m_networkTable->GetEntry("isHaveTarget");
    m_spinError = m_networkTable->GetEntry("SpinError");
}

double JetsonNanoCamera::GetSpinError() {
    return m_spinError.GetDouble(0.0);
}

bool JetsonNanoCamera::GetIsHaveTarget() {
    return m_isHaveTarget.GetBoolean(false);
}
