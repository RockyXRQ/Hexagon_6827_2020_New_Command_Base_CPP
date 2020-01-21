/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Turret.h"

Turret::Turret() {
    m_shootLeftMotor.SetNeutralMode(NeutralMode::Coast);
    m_shootRightMotor.SetNeutralMode(NeutralMode::Coast);
    m_aimMotor.SetNeutralMode(NeutralMode::Brake);

    m_shootLeftMotor.Follow(m_shootRightMotor);
    m_shootLeftMotor.SetInverted(InvertType::OpposeMaster);

    SetName("Turret");
}

void Turret::Shoot() {
    m_shootRightMotor.Set(ControlMode::PercentOutput, 1);
}

void Turret::StopShoot() {
    m_shootRightMotor.Set(ControlMode::PercentOutput, 0);
}

void Turret::AimSpin(double spinSpeed) {
    m_aimMotor.Set(ControlMode::PercentOutput, spinSpeed);
}

void Turret::Log() {
}

void Turret::Reset() {
}