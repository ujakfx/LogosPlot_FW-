/*
---------------------------------------------------------------
 Logos Robotics SDK

 File:
    CoreXYKinematics_Test.cpp

 Purpose:
    Verifies CoreXY kinematics transformation.

 Module:
    Tests

 Build:
    002

 License:
    MIT
---------------------------------------------------------------
*/

#include <iostream>

#include "../sdk/kinematics/CoreXYKinematics.h"

using namespace LogosRobotics;

//---------------------------------------------------------------
// Helper functions
//---------------------------------------------------------------

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

//---------------------------------------------------------------
// Test execution
//---------------------------------------------------------------

void runTest(
    Kinematics::CoreXYKinematics& coreXY,
    const Core::Position& position,
    const char* name)
{
    Core::MotorCommandBuffer commands;

    Core::Result result =
        coreXY.transform(position, commands);

    std::cout
        << "========================================\n";

    std::cout
        << "Test : "
        << name
        << '\n';

    std::cout
        << "Input: X="
        << position.x
        << "  Y="
        << position.y
        << "\n\n";

    if (result != Core::Result::Ok)
    {
        std::cout
            << "Transformation FAILED\n";

        std::cout
            << "========================================\n\n";

        return;
    }

    std::cout
        << "Command count: "
        << static_cast<int>(commands.count)
        << "\n\n";

    for (std::uint8_t i = 0; i < commands.count; ++i)
    {
        const auto& command = commands.commands[i];

        std::cout
            << "Motor: "
            << motorName(command.motor)
            << '\n';

        std::cout
            << "Direction: "
            << directionName(command.direction)
            << '\n';

        std::cout
            << "Steps: "
            << command.steps
            << "\n\n";
    }

    std::cout
        << "========================================\n\n";
}

//---------------------------------------------------------------
// Main
//---------------------------------------------------------------

int main()
{
    std::cout
        << "========================================\n"
        << " Logos Robotics SDK\n"
        << " CoreXY Kinematics Test Suite\n"
        << " Build 002\n"
        << "========================================\n\n";

    Kinematics::CoreXYKinematics coreXY;

    if (coreXY.initialize() != Core::Result::Ok)
    {
        std::cout
            << "CoreXY initialization failed.\n";

        return 1;
    }

    runTest(coreXY, { 100,   0 }, "Positive X");
    runTest(coreXY, {   0, 100 }, "Positive Y");
    runTest(coreXY, {  50,  50 }, "Diagonal");
    runTest(coreXY, {  50, -50 }, "Negative Y");
    runTest(coreXY, {-100,   0 }, "Negative X");

    std::cout
        << "========================================\n"
        << "All tests completed.\n"
        << "========================================\n";

    return 0;
}