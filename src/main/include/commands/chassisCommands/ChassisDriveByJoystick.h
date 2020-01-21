/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "subsystems/Chassis.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class ChassisDriveByJoystick
    : public frc2::CommandHelper<frc2::CommandBase, ChassisDriveByJoystick> {
   public:
    ChassisDriveByJoystick(std::function<double()>, std::function<double()>,
                           Chassis*);
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

   private:
    std::function<double()> m_stright;
    std::function<double()> m_turn;
    Chassis* m_chassis;
};
