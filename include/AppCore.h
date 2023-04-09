#ifndef APP_CORE
#define APP_CORE

#include <memory>

class MotorController;
using motor_controller_up = std::unique_ptr<MotorController>;

struct MotorControllerConfig;

class AppCore
{
private:
    motor_controller_up m_left_motor;
    motor_controller_up m_right_motor;
public:
    AppCore(const MotorControllerConfig &motor_controller_config);
    ~AppCore();
};

#endif