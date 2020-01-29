/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/intakeCommands/IntakeIn.h"

IntakeIn::IntakeIn(Intake* intake) : m_intake{intake} {
    SetName("Intake In");
    AddRequirements({m_intake});
}

// Called repeatedly when this Command is scheduled to run
void IntakeIn::Execute() {
    m_intake->In();
}

// Returns true when the command should end.
bool IntakeIn::IsFinished() {
    return true;
}

// Called once the command ends or is interrupted.
void IntakeIn::End(bool interrupted) {
    m_intake->Lock();
}
