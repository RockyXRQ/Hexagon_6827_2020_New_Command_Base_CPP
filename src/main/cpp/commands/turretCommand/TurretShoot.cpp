/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/turretCommand/TurretShoot.h"

TurretShoot::TurretShoot(Turret* turret) : m_turret{turret} {
    SetName("Turret Shoot");
    AddRequirements({m_turret});
}

// Called repeatedly when this Command is scheduled to run
void TurretShoot::Execute() {
    m_turret->Shoot();
}
// Returns true when the command should end.
bool TurretShoot::IsFinished() {
    return true;
}
// Called once the command ends or is interrupted.
void TurretShoot::End(bool interrupted) {
    m_turret->StopShoot();
}
