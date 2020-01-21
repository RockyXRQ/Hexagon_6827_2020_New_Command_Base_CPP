/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

using constants::turret::TURRET_AIM_MOTOR_ID;
using constants::turret::TURRET_SHOOT_LEFT_MOTOR_ID;
using constants::turret::TURRET_SHOOT_RIGHT_MOTOR_ID;

using ctre::phoenix::motorcontrol::can::VictorSPX;

class Turret : public frc2::SubsystemBase {
   public:
    explicit Turret();
    void Shoot();
    void StopShoot();
    void AimSpin(double spinSpeed = 0);
    void Log();
    void Reset();

   private:
    VictorSPX m_shootLeftMotor{TURRET_SHOOT_LEFT_MOTOR_ID};
    VictorSPX m_shootRightMotor{TURRET_SHOOT_RIGHT_MOTOR_ID};
    VictorSPX m_aimMotor{TURRET_AIM_MOTOR_ID};
};
