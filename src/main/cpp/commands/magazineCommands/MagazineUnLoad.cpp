/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/magazineCommands/MagazineUnLoad.h"

MagazineUnLoad::MagazineUnLoad(Magazine* magazine) : m_magazine{magazine} {
    SetName("Magazine Unload");
    AddRequirements({m_magazine});
}

// Called repeatedly when this Command is scheduled to run
void MagazineUnLoad::Execute() {
    m_magazine->UnLoad();
}

// Returns true when the command should end.
bool MagazineUnLoad::IsFinished() {
    return true;
}

// Called once the command ends or is interrupted.
void MagazineUnLoad::End(bool interrupted) {
    m_magazine->Lock();
}