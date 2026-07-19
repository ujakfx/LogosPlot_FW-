/*
---------------------------------------------------------------
 Logos Robotics SDK

 File:
    MotionEngine_Test.cpp

 Purpose:
    Motion Engine integration test.

 Module:
    Tests

 Build:
    004

 License:
    MIT
---------------------------------------------------------------
*/

#include <iostream>

#include "MotionEngine.h"
#include "CoreXYKinematics.h"
#include "DesktopMockHal.h"

using namespace LogosRobotics;

int main()
{
    std::cout << "========================================\n";
    std::cout << " Logos Robotics SDK\n";
    std::cout << " Motion Engine Test\n";
    std::cout << " Build 004\n";
    std::cout << "========================================\n\n";

    Hal::DesktopMockHal hal;
    Kinematics::CoreXYKinematics kinematics;
    Motion::MotionEngine engine(kinematics, hal);

    Core::Result result = engine.initialize();

    if (result != Core::Result::Ok)
    {
        std::cout << "Initialization failed.\n";
        return -1;
    }

    Core::Position position;
    position.x = 100;
    position.y = 50;

    result = engine.moveTo(position);

    if (result == Core::Result::Ok)
    {
        std::cout << "Motion Engine test passed.\n";
    }
    else
    {
        std::cout << "Motion Engine test failed.\n";
    }

    return 0;
}