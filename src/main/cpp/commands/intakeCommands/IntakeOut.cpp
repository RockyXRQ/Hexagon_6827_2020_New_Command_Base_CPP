/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/intakeCommands/IntakeOut.h"

IntakeOut::IntakeOut(Intake* intake) : m_intake{intake} {
    SetName("Intake Out");
    AddRequirements({m_intake});
}

// Called repeatedly when this Command is scheduled to run
void IntakeOut::Execute() {
    m_intake->Out();
}

// Returns true when the command should end.
bool IntakeOut::IsFinished() {
    return false;
}

// Called once the command ends or is interrupted.
void IntakeOut::End(bool interrupted) {
    m_intake->Lock();
}
