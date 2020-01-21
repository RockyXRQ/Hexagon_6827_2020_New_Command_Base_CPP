/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SuperStructureUnLoadTheBall.h"

#include "commands/intakeCommands/IntakeOut.h"
#include "commands/magazineCommands/MagazineUnLoad.h"

SuperStructureUnLoadTheBall::SuperStructureUnLoadTheBall(Intake* intake,
                                                         Magazine* magazine) {
    AddCommands(IntakeOut(intake), MagazineUnLoad(magazine));
}