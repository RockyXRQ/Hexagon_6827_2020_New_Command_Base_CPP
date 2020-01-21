/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Constants.h"

#include <frc2/command/SubsystemBase.h>
#include <frc/SPI.h>
#include <frc/Encoder.h>
#include <frc/ADXRS450_Gyro.h>
#include <ctre/Phoenix.h>

using constants::chassis::CHASSIS_GYRO_SPI_PORT;
using constants::chassis::CHASSIS_LB_MOTOR_ID;
using constants::chassis::CHASSIS_LEFT_ENCODER_PORT_A;
using constants::chassis::CHASSIS_LEFT_ENCODER_PORT_B;
using constants::chassis::CHASSIS_LF_MOTOR_ID;
using constants::chassis::CHASSIS_RB_MOTOR_ID;
using constants::chassis::CHASSIS_RF_MOTOR_ID;
using constants::chassis::CHASSIS_RIGHT_ENCODER_PORT_A;
using constants::chassis::CHASSIS_RIGHT_ENCODER_PORT_B;

using ctre::phoenix::motorcontrol::can::VictorSPX;

class Chassis : public frc2::SubsystemBase {
   public:
    explicit Chassis();
    void Log();
    void Drive(double strightSpeed = 0, double turnSpeed = 0);
    void Reset();
    double GetDistance();

   private:
    VictorSPX m_lf{CHASSIS_LF_MOTOR_ID};
    VictorSPX m_lb{CHASSIS_LB_MOTOR_ID};
    VictorSPX m_rf{CHASSIS_RF_MOTOR_ID};
    VictorSPX m_rb{CHASSIS_RB_MOTOR_ID};

    frc::Encoder m_leftEncoder{CHASSIS_LEFT_ENCODER_PORT_A,
                               CHASSIS_LEFT_ENCODER_PORT_B};
    frc::Encoder m_rightEncoder{CHASSIS_RIGHT_ENCODER_PORT_A,
                                CHASSIS_RIGHT_ENCODER_PORT_B};

    frc::ADXRS450_Gyro m_gyro{CHASSIS_GYRO_SPI_PORT};
};