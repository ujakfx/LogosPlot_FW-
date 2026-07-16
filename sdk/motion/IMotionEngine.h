/*
---------------------------------------------------------------
 Logos Robotics SDK

 File:
    IMotionEngine.h

 Purpose:
    Motion Engine interface.

 Module:
    Motion

 Build:
    004

 License:
    MIT
---------------------------------------------------------------
*/

#pragma once

#include "../core/Position.h"
#include "../core/Result.h"

namespace LogosRobotics
{
namespace Motion
{

class IMotionEngine
{
public:

    virtual ~IMotionEngine() = default;

    virtual Core::Result initialize() = 0;

    virtual Core::Result moveTo(
        const Core::Position& position) = 0;
};

}
}