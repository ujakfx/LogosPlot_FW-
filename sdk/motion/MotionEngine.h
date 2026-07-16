/*
---------------------------------------------------------------
 Logos Robotics SDK

 File:
    MotionEngine.h

 Purpose:
    Motion Engine implementation.

 Module:
    Motion

 Build:
    004

 License:
    MIT
---------------------------------------------------------------
*/

#pragma once

#include "IMotionEngine.h"

#include "../hal/IHal.h"
#include "../kinematics/IKinematics.h"

namespace LogosRobotics::Motion
{

class MotionEngine : public IMotionEngine
{
public:

    MotionEngine(
        Kinematics::IKinematics& kinematics,
        Hal::IHal& hal);

    Core::Result initialize() override;

    Core::Result moveTo(
        const Core::Position& position) override;

private:

    Kinematics::IKinematics& m_kinematics;

    Hal::IHal& m_hal;
};

} // namespace LogosRobotics::Motion