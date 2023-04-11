#ifndef APP_CORE
#define APP_CORE

#include <memory>
#include "Directions.h"

class MotorController;
using motor_controller_up = std::unique_ptr<MotorController>;

struct MotorControllerConfig;

class AsyncWebServer;
using async_web_server_up = std::unique_ptr<AsyncWebServer>;


class AppCore
{
private:
    motor_controller_up m_left_motor;
    motor_controller_up m_right_motor;
    async_web_server_up m_server;
public:
    AppCore(const MotorControllerConfig &motor_controller_config);
    ~AppCore();
private:
    void init_web_server();
    void move(Directions direction, std::uint8_t speed);
};

#endif