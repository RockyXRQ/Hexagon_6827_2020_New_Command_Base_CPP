/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "subsystems/Turret.h"
#include "subsystems/JetsonNanoCamera.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>

class TurretAutoAim
    : public frc2::CommandHelper<frc2::CommandBase, TurretAutoAim> {
   public:
    TurretAutoAim(Turret*, JetsonNanoCamera*, double kp = 0, double ki = 0,
                  double kd = 0);
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

   private:
    JetsonNanoCamera* m_camera;
    Turret* m_turret;

    frc2::PIDController m_pidController;
};
