/*
---------------------------------------------------------------
 Logos Robotics SDK

 File:
    MotionEngine.cpp

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

#include "MotionEngine.h"

namespace LogosRobotics::Motion
{

MotionEngine::MotionEngine(
    Kinematics::IKinematics& kinematics,
    Hal::IHal& hal)
    :
    m_kinematics(kinematics),
    m_hal(hal)
{
}

Core::Result MotionEngine::initialize()
{
    return m_hal.initialize();
}

Core::Result MotionEngine::moveTo(
    const Core::Position& position)
{
    Core::MotorCommandBuffer commands;

    Core::Result result =
        m_kinematics.transform(position, commands);

    if (result != Core::Result::Ok)
    {
        return result;
    }

    for (std::uint8_t i = 0; i < commands.count; ++i)
    {
        const auto& command = commands.commands[i];

        result = m_hal.enableMotor(command.motor);

        if (result != Core::Result::Ok)
        {
            return result;
        }

        result = m_hal.setDirection(
            command.motor,
            command.direction);

        if (result != Core::Result::Ok)
        {
            return result;
        }

        for (Core::StepCount step = 0;
             step < command.steps;
             ++step)
        {
            result = m_hal.stepMotor(command.motor);

            if (result != Core::Result::Ok)
            {
                return result;
            }
        }

        result = m_hal.disableMotor(command.motor);

        if (result != Core::Result::Ok)
        {
            return result;
        }
    }

    return Core::Result::Ok;
}

} // namespace LogosRobotics::Motion