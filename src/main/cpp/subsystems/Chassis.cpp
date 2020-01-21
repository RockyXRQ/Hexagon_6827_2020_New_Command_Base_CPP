/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Chassis.h"

#include <frc/smartdashboard/SmartDashboard.h>

Chassis::Chassis() {
    m_leftEncoder.SetDistancePerPulse(0.042);
    m_rightEncoder.SetDistancePerPulse(0.042);

    m_lb.Follow(m_lf);
    m_rb.Follow(m_rf);

    m_lb.SetInverted(InvertType::OpposeMaster);
    m_rb.SetInverted(InvertType::OpposeMaster);

    m_lf.SetNeutralMode(NeutralMode::Brake);
    m_lb.SetNeutralMode(NeutralMode::Brake);
    m_rf.SetNeutralMode(NeutralMode::Brake);
    m_rb.SetNeutralMode(NeutralMode::Brake);

    SetName("Chassis");
    AddChild("Left Encoder", &m_leftEncoder);
    AddChild("Right Encoder", &m_rightEncoder);
    AddChild("Gyro", &m_gyro);
}

void Chassis::Log() {
    frc::SmartDashboard::PutNumber("Left Distance",
                                   m_leftEncoder.GetDistance());
    frc::SmartDashboard::PutNumber("Right Distance",
                                   m_rightEncoder.GetDistance());
    frc::SmartDashboard::PutNumber("Left Speed", m_leftEncoder.GetRate());
    frc::SmartDashboard::PutNumber("Right Speed", m_rightEncoder.GetRate());
    frc::SmartDashboard::PutNumber("Gyro", m_gyro.GetAngle());
}

void Chassis::Drive(double strightSpeed, double turnSpeed) {
    m_lf.Set(ControlMode::PercentOutput, strightSpeed + turnSpeed);
    m_rf.Set(ControlMode::PercentOutput, strightSpeed - turnSpeed);
}

void Chassis::Reset() {
    m_leftEncoder.Reset();
    m_rightEncoder.Reset();
    m_gyro.Reset();
}

double Chassis::GetDistance() {
    return (m_leftEncoder.GetDistance() + m_rightEncoder.GetDistance()) / 2.0;
}
