/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/magazineCommands/MagazineLoad.h"

MagazineLoad::MagazineLoad(Magazine* magazine) : m_magazine{magazine} {
    SetName("Magazine Load");
    AddRequirements({m_magazine});
}

// Called repeatedly when this Command is scheduled to run
void MagazineLoad::Execute() {
    m_magazine->Load();
}

// Returns true when the command should end.
bool MagazineLoad::IsFinished() {
    return true;
}

// Called once the command ends or is interrupted.
void MagazineLoad::End(bool interrupted) {
    m_magazine->Lock();
}
