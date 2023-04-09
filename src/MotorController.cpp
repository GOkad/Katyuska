#include "MotorController.h"

MotorController::MotorController(std::uint8_t positive_pin, std::uint8_t negative_pin):
    {
        m_positive_pin{positive_pin},
        m_negative_pin{negative_pin}
    }
{

}