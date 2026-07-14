/*
---------------------------------------------------------------
 Logos Robotics SDK

 File:
    DesktopMockHal.cpp

 Purpose:
    Desktop mock implementation of the Hardware Abstraction Layer.

 Module:
    HAL

 Build:
    003

 License:
    MIT
---------------------------------------------------------------
*/

#include "DesktopMockHal.h"

#include <iostream>

namespace LogosRobotics::Hal
{

namespace
{

const char* motorName(Core::Motor motor)
{
    switch (motor)
    {
        case Core::Motor::A: return "A";
        case Core::Motor::B: return "B";
        case Core::Motor::C: return "C";
        case Core::Motor::D: return "D";
    }

    return "Unknown";
}

const char* directionName(Core::Direction direction)
{
    switch (direction)
    {
        case Core::Direction::Positive:
            return "Positive";

        case Core::Direction::Negative:
            return "Negative";
    }

    return "Unknown";
}

} // anonymous namespace

//---------------------------------------------------------------

Core::Result DesktopMockHal::initialize()
{
    std::cout
        << "[HAL] DesktopMockHal initialized.\n";

    return Core::Result::Ok;
}

//---------------------------------------------------------------

Core::Result DesktopMockHal::enableMotor(
    Core::Motor motor)
{
    std::cout
        << "[HAL] Enable Motor "
        << motorName(motor)
        << '\n';

    return Core::Result::Ok;
}

//---------------------------------------------------------------

Core::Result DesktopMockHal::disableMotor(
    Core::Motor motor)
{
    std::cout
        << "[HAL] Disable Motor "
        << motorName(motor)
        << '\n';

    return Core::Result::Ok;
}

//---------------------------------------------------------------

Core::Result DesktopMockHal::setDirection(
    Core::Motor motor,
    Core::Direction direction)
{
    std::cout
        << "[HAL] Motor "
        << motorName(motor)
        << " Direction -> "
        << directionName(direction)
        << '\n';

    return Core::Result::Ok;
}

//---------------------------------------------------------------

Core::Result DesktopMockHal::stepMotor(
    Core::Motor motor)
{
    std::cout
        << "[HAL] STEP "
        << motorName(motor)
        << '\n';

    return Core::Result::Ok;
}

} // namespace LogosRobotics::Hal