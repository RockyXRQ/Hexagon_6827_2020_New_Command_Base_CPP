/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"

#include "commands/turretCommand/TurretLeftSpin.h"

TurretLeftSpin::TurretLeftSpin(Turret* turret) : m_turret{turret} {
    SetName("Turret Left Spin");
    AddRequirements(m_turret);
}

// Called repeatedly when this Command is scheduled to run
void TurretLeftSpin::Execute() {
    m_turret->AimSpin(constants::turret::TURRET_MANUAL_AIM_SPEED);
}

// Returns true when the command should end.
bool TurretLeftSpin::IsFinished() {
    return false;
}

// Called once the command ends or is interrupted.
void TurretLeftSpin::End(bool interrupted) {
    m_turret->AimSpin(0);
}
