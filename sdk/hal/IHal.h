/*
---------------------------------------------------------------
 Logos Robotics SDK

 File:
    IHal.h

 Purpose:
    Hardware Abstraction Layer interface.

 Module:
    HAL

 Build:
    003

 License:
    MIT
---------------------------------------------------------------
*/

#pragma once

#include "../core/Direction.h"
#include "../core/Motor.h"
#include "../core/Result.h"

namespace LogosRobotics::Hal
{

class IHal
{
public:

    virtual ~IHal() = default;

    virtual Core::Result initialize() = 0;

    virtual Core::Result enableMotor(
        Core::Motor motor) = 0;

    virtual Core::Result disableMotor(
        Core::Motor motor) = 0;

    virtual Core::Result setDirection(
        Core::Motor motor,
        Core::Direction direction) = 0;

    virtual Core::Result stepMotor(
        Core::Motor motor) = 0;
};

} // namespace LogosRobotics::Hal