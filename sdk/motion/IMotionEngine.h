/*
---------------------------------------------------------------
 Logos Robotics SDK

 File:
    IMotionEngine.h

 Purpose:
    Defines the motion execution interface.

 Module:
    Motion

 Build:
    001

 License:
    MIT
---------------------------------------------------------------
*/

#pragma once

#include "../core/Motor.h"
#include "../core/Direction.h"
#include "../core/Result.h"
#include "../core/Types.h"

namespace LogosRobotics::Motion
{

class IMotionEngine
{
public:

    virtual ~IMotionEngine() = default;

    virtual Core::Result initialize() = 0;

    virtual Core::Result execute(
            Core::Motor motor,
            Core::Direction direction,
            Core::StepCount steps) = 0;

    virtual Core::Result stop() = 0;

    virtual bool isBusy() const = 0;

};

} // namespace LogosRobotics::Motion
