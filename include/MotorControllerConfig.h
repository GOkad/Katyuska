#ifndef MOTOR_CONTROLLER_CONFIG
#define MOTOR_CONTROLLER_CONFIG

#include <cstdint>

struct MotorControllerConfig
{
    /**
     * Left Motor Negative pin
     * D1
     */
    static inline const std::uint8_t LEFT_MOTOR_POS_PIN = 5;
    // D2
    static inline const std::uint8_t LEFT_MOTOR_NEG_PIN = 4;
    // D3
    static inline const std::uint8_t RIGHT_MOTOR_POS_PIN = 0;
    // D4
    static inline const std::uint8_t RIGHT_MOTOR_NEG_PIN = 2;

    const std::uint8_t left_motor_pos_pin{LEFT_MOTOR_POS_PIN};
    const std::uint8_t left_motor_neg_pin{LEFT_MOTOR_NEG_PIN};
    const std::uint8_t right_motor_pos_pin{RIGHT_MOTOR_POS_PIN};
    const std::uint8_t right_motor_neg_pin{RIGHT_MOTOR_NEG_PIN};
};


#endif