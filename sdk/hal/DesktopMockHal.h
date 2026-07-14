class DesktopMockHal : public IHal
{
public:

    Core::Result initialize() override;

    Core::Result enableMotor(
        Core::Motor motor) override;

    Core::Result disableMotor(
        Core::Motor motor) override;

    Core::Result setDirection(
        Core::Motor motor,
        Core::Direction direction) override;

    Core::Result stepMotor(
        Core::Motor motor) override;
};