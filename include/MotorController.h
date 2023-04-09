#ifndef MOTOR_CONTROLLER
#define MOTOR_CONTROLLER

#include <cstdint>

class MotorController
{
private:
    std::uint8_t m_positive_pin;
    std::uint8_t m_negative_pin;
public:
    MotorController(std::uint8_t positive_pin, std::uint8_t negative_pin);
};

#endif