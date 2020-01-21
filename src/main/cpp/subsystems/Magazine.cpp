/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Magazine.h"

Magazine::Magazine() {
    m_spinHighMotor.Follow(m_spinLowMotor);
    m_spinHighMotor.SetInverted(InvertType::OpposeMaster);

    SetName("Magazine");
}

void Magazine::Log() {
}

void Magazine::Load() {
    m_spinLowMotor.Set(ControlMode::PercentOutput, 1);
}

void Magazine::UnLoad() {
    m_spinLowMotor.Set(ControlMode::PercentOutput, -1);
}

void Magazine::Lock() {
    m_spinLowMotor.Set(ControlMode::PercentOutput, 0);
}

void Magazine::Reset() {
}