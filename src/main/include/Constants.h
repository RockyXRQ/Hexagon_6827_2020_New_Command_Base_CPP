/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/ADXRS450_Gyro.h>

namespace constants {
namespace joystick {
constexpr int CHASSIS_JOYSTICK_PORT = 0;
constexpr int SUPERSTRUCTURE_JOYSTICK_PORT = 1;
}  // namespace joystick
namespace chassis {
constexpr int CHASSIS_LF_MOTOR_ID = 1;
constexpr int CHASSIS_LB_MOTOR_ID = 2;
constexpr int CHASSIS_RF_MOTOR_ID = 3;
constexpr int CHASSIS_RB_MOTOR_ID = 4;

constexpr int CHASSIS_LEFT_ENCODER_PORT_A = 0;
constexpr int CHASSIS_LEFT_ENCODER_PORT_B = 1;

constexpr int CHASSIS_RIGHT_ENCODER_PORT_A = 2;
constexpr int CHASSIS_RIGHT_ENCODER_PORT_B = 3;

constexpr frc::SPI::Port CHASSIS_GYRO_SPI_PORT = frc::SPI::Port::kOnboardCS0;
}  // namespace chassis
namespace intake {
constexpr int INTAKE_SPIN_MOTOR_ID = 5;
constexpr int INTAKE_SPIN_ENCODER_PORT_A = 4;
constexpr int INTAKE_SPIN_ENCODER_PORT_B = 5;
}  // namespace intake
namespace magazine {
constexpr int MAGAZINE_SPIN_HIGH_MOTOR_ID = 6;
constexpr int MAGAZINE_SPIN_LOW_MOTOR_ID = 7;
}  // namespace magazine
namespace turret {
constexpr int TURRET_SHOOT_LEFT_MOTOR_ID = 8;
constexpr int TURRET_SHOOT_RIGHT_MOTOR_ID = 9;
constexpr int TURRET_AIM_MOTOR_ID = 10;

constexpr double TURRET_MANUAL_AIM_SPEED = 0.8;
}  // namespace turret
}  // namespace constants