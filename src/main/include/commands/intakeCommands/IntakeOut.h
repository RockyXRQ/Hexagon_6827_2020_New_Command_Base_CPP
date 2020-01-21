/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "subsystems/Intake.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class IntakeOut : public frc2::CommandHelper<frc2::CommandBase, IntakeOut> {
   public:
    IntakeOut(Intake*);
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

   private:
    Intake* m_intake;
};
