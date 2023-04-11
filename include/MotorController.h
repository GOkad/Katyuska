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
    void stop();
    void forward(std::uint8_t speed);
    void reverse(std::uint8_t speed);
};

#endif