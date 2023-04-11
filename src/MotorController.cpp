#include <Arduino.h>
#include "MotorController.h"

MotorController::MotorController(
    std::uint8_t positive_pin,
    std::uint8_t negative_pin
):    
    m_positive_pin{positive_pin},
    m_negative_pin{negative_pin}
{
    pinMode(m_positive_pin, OUTPUT);
    pinMode(m_negative_pin, OUTPUT);
}

void MotorController::stop()
{
    digitalWrite(m_positive_pin, LOW);
    digitalWrite(m_negative_pin, LOW);
}

void MotorController::forward(std::uint8_t speed)
{
    digitalWrite(m_positive_pin, HIGH);
    digitalWrite(m_negative_pin, LOW);
}

void MotorController::reverse(std::uint8_t speed)
{
    digitalWrite(m_positive_pin, LOW);
    digitalWrite(m_negative_pin, HIGH);
}
