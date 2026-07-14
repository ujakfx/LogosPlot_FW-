/*
---------------------------------------------------------------
 Logos Robotics SDK

 File:
    Types.h

 Purpose:
    Defines common SDK data types shared across all modules.

 Module:
    Core

 Build:
    001

 License:
    MIT
---------------------------------------------------------------
*/

#pragma once

#include <cstdint>

namespace LogosRobotics::Core
{

using Coordinate = std::int32_t;   // Logical coordinates

using StepCount  = std::uint32_t;  // Number of motor steps

using Speed = std::uint32_t;

using TimeUs = std::uint32_t;

}