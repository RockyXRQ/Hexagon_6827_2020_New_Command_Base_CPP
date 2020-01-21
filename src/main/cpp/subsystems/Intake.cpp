/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Intake.h"

#include <frc/smartdashboard/SmartDashboard.h>

Intake::Intake() {
    m_spinMotor.SetNeutralMode(NeutralMode::Brake);
    m_spinMotor.EnableVoltageCompensation(true);

    SetName("Intake");
    AddChild("Spin Encoder", &m_spinEncoder);
}

void Intake::Log() {
    frc::SmartDashboard::PutNumber("Spin Speed", m_spinEncoder.GetRate());
}

void Intake::In() {
    m_spinMotor.Set(ControlMode::PercentOutput, 1);
}

void Intake::Out() {
    m_spinMotor.Set(ControlMode::PercentOutput, -1);
}

void Intake::Lock() {
    m_spinMotor.Set(ControlMode::PercentOutput, 0);
}

void Intake::Reset() {
    m_spinEncoder.Reset();
}
