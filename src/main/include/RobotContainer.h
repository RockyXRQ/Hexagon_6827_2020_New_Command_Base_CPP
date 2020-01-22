/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Constants.h"

#include "subsystems/Chassis.h"
#include "subsystems/Intake.h"
#include "subsystems/Magazine.h"
#include "subsystems/Turret.h"
#include "subsystems/JetsonNanoCamera.h"

#include <frc2/command/Command.h>
#include <frc/joystick.h>
/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
   public:
    RobotContainer();

   private:
    frc::Joystick m_chassisDrive{constants::joystick::CHASSIS_JOYSTICK_PORT};
    frc::Joystick m_superStructureDrive{
        constants::joystick::SUPERSTRUCTURE_JOYSTICK_PORT};

    Chassis m_chassis;
    Intake m_intake;
    Magazine m_magazine;
    Turret m_turret;

    JetsonNanoCamera m_camera;

    void ConfigureButtonBindings();
};
