#include "AppCore.h"
#include "MotorControllerConfig.h"
#include "MotorController.h"

AppCore::AppCore(const MotorControllerConfig &motor_controller_config):
    m_left_motor{std::make_unique<MotorController>(motor_controller_config.left_motor_neg_pin, motor_controller_config.left_motor_pos_pin)},
    m_right_motor{std::make_unique<MotorController>(motor_controller_config.left_motor_neg_pin, motor_controller_config.left_motor_pos_pin)}
{

}

AppCore::~AppCore() = default;