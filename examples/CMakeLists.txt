#include "../sdk/hal/DesktopMockHal.h"

using namespace LogosRobotics;

int main()
{
    Hal::DesktopMockHal hal;

    hal.initialize();

    hal.enableMotor(Core::Motor::A);

    hal.setDirection(
        Core::Motor::A,
        Core::Direction::Positive);

    for (int i = 0; i < 10; ++i)
    {
        hal.stepMotor(Core::Motor::A);
    }

    hal.disableMotor(Core::Motor::A);

    return 0;
}