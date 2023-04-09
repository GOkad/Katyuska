#ifndef MOTOR_CONTROLLER_CONFIG
#define MOTOR_CONTROLLER_CONFIG

#include <cstdint>

struct MotorControllerConfig
{
    /**
     * Left Motor Negative pin
     *  
     */
    static inline const std::uint8_t LEFT_MOTOR_POS_PIN = 0;
    static inline const std::uint8_t LEFT_MOTOR_NEG_PIN = 0;
    static inline const std::uint8_t RIGHT_MOTOR_POS_PIN = 0;
    static inline const std::uint8_t RIGHT_MOTOR_NEG_PIN = 0;

    const std::uint8_t left_motor_pos_pin{LEFT_MOTOR_POS_PIN};
    const std::uint8_t left_motor_neg_pin{LEFT_MOTOR_NEG_PIN};
    const std::uint8_t right_motor_pos_pin{RIGHT_MOTOR_POS_PIN};
    const std::uint8_t right_motor_neg_pin{RIGHT_MOTOR_NEG_PIN};
};


#endif