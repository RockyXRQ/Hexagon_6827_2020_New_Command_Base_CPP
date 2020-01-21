/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SuperStructureLoadTheBall.h"

#include "commands/intakeCommands/IntakeIn.h"
#include "commands/magazineCommands/MagazineLoad.h"

SuperStructureLoadTheBall::SuperStructureLoadTheBall(Intake* intake,
                                                     Magazine* magazine) {
    SetName("Superstructure Load");
    AddCommands(IntakeIn(intake), MagazineLoad(magazine));
}
