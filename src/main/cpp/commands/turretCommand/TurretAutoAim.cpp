/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"

#include "commands/turretCommand/TurretAutoAim.h"

TurretAutoAim::TurretAutoAim(Turret* turret, JetsonNanoCamera* camera,
                             double kp, double ki, double kd)
    : m_turret{turret}, m_camera{camera}, m_pidController(kp, ki, kd) {
    SetName("Turret Auto Aim");
    AddRequirements({m_turret});
    AddRequirements({m_camera});
}

// Called repeatedly when this Command is scheduled to run
void TurretAutoAim::Execute() {
    if (m_camera->GetIsHaveTarget())
        m_turret->AimSpin(m_pidController.Calculate(m_camera->GetSpinError()));
    else
        m_turret->AimSpin(constants::turret::TURRET_AUTO_AIM_SEARCHING_SPEED);
}

// Returns true when the command should end.
bool TurretAutoAim::IsFinished() {
    return false;
}

// Called once the command ends or is interrupted.
void TurretAutoAim::End(bool interrupted) {
    m_turret->AimSpin(0.0);
}
