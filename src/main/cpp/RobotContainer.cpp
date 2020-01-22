/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

#include "Constants.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/chassisCommands/ChassisDriveByJoystick.h"

#include "commands/intakeCommands/IntakeIn.h"
#include "commands/intakeCommands/IntakeOut.h"

#include "commands/magazineCommands/MagazineLoad.h"
#include "commands/magazineCommands/MagazineUnLoad.h"

#include "commands/turretCommand/TurretLeftSpin.h"
#include "commands/turretCommand/TurretRightSpin.h"
#include "commands/turretCommand/TurretShoot.h"
#include "commands/turretCommand/TurretAutoAim.h"

#include "commands/SuperStructureLoadTheBall.h"
#include "commands/SuperStructureUnLoadTheBall.h"

using constants::turret::TURRET_AUTO_AIM_KD;
using constants::turret::TURRET_AUTO_AIM_KI;
using constants::turret::TURRET_AUTO_AIM_KP;

RobotContainer::RobotContainer() {
    frc::SmartDashboard::PutData(&m_chassis);
    frc::SmartDashboard::PutData(&m_intake);
    frc::SmartDashboard::PutData(&m_magazine);
    frc::SmartDashboard::PutData(&m_turret);

    m_chassis.Reset();
    m_intake.Reset();
    m_magazine.Reset();
    m_turret.Reset();

    m_chassis.Log();
    m_intake.Log();
    m_magazine.Log();
    m_turret.Log();

    m_chassis.SetDefaultCommand(ChassisDriveByJoystick(
        [this] {
            return m_chassisDrive.GetRawAxis(3) - m_chassisDrive.GetRawAxis(2);
        },
        [this] { return m_chassisDrive.GetRawAxis(0); }, &m_chassis));

    ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
    frc2::JoystickButton m_loadButton(&m_superStructureDrive,
                                      0);  // Xbox One Joystick A.
    frc2::JoystickButton m_unLoadButton(&m_superStructureDrive,
                                        3);  // Xbox One Joystick Y.
    frc2::JoystickButton m_leftSpinButton(&m_superStructureDrive,
                                          4);  // Xbox One Joystick LB.
    frc2::JoystickButton m_rightSpinButton(&m_superStructureDrive,
                                           5);  // Xbox One Joystick RB.

    frc2::JoystickButton m_shootButton(&m_superStructureDrive,
                                       1);  // Xbox One Joystick B.

    frc2::JoystickButton m_autoAimButton(&m_superStructureDrive,
                                         2);  // Xbox One Joystick X.

    m_loadButton.WhenHeld(SuperStructureLoadTheBall(&m_intake, &m_magazine));
    m_unLoadButton.WhenHeld(
        SuperStructureUnLoadTheBall(&m_intake, &m_magazine));
    m_leftSpinButton.WhenHeld(TurretLeftSpin(&m_turret));
    m_rightSpinButton.WhenHeld(TurretRightSpin(&m_turret));

    m_shootButton.WhenPressed(TurretShoot(&m_turret));
    m_autoAimButton.WhenPressed(
        TurretAutoAim(&m_turret, &m_camera, TURRET_AUTO_AIM_KP,
                      TURRET_AUTO_AIM_KI, TURRET_AUTO_AIM_KD));
}