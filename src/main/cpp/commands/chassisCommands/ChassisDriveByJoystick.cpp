/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/chassisCommands/ChassisDriveByJoystick.h"

ChassisDriveByJoystick::ChassisDriveByJoystick(std::function<double()> stright,
                                               std::function<double()> turn,
                                               Chassis* chassis)
    : m_stright{stright}, m_turn{turn}, m_chassis{chassis} {
    SetName("Chassis drive by Joystick");
    AddRequirements({m_chassis});
}

// Called repeatedly when this Command is scheduled to run
void ChassisDriveByJoystick::Execute() {
    m_chassis->Drive(m_stright(), m_turn());
}

// Returns true when the command should end.
bool ChassisDriveByJoystick::IsFinished() {
    return false;
}

// Called once the command ends or is interrupted.
void ChassisDriveByJoystick::End(bool interrupted) {
    m_chassis->Drive(0, 0);
}
