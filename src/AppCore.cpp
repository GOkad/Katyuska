#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "AppCore.h"
#include "MotorControllerConfig.h"
#include "MotorController.h"
#include "Directions.h"
#include "HTMLInterface.h"

AppCore::AppCore(const MotorControllerConfig &motor_controller_config):
    m_left_motor{std::make_unique<MotorController>(4,5)},
    m_right_motor{std::make_unique<MotorController>(15,2)},
    m_server{std::make_unique<AsyncWebServer>(80)}
{
    init_web_server();
}

AppCore::~AppCore() = default;

void AppCore::init_web_server()
{
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP("Katyushka","");

    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP().toString());

    m_server->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", html_interface);
    });

    m_server->on("/update", HTTP_GET, [core = this](AsyncWebServerRequest *request){
        std::uint8_t speed = 0;
        Directions direction = Directions::STOP;
        if(request->hasParam("speed"))
        {
            speed = std::stoi(request->getParam("speed")->value().c_str());
        }

        if(request->hasParam("dir"))
        {
            std::uint8_t dir = std::stoi(request->getParam("dir")->value().c_str());
            direction = static_cast<Directions>(dir);
        }

        Serial.print("Speed: ");
        Serial.println(speed);

        Serial.print("Direction: ");
        Serial.println(direction);

        Serial.println("-----------");

        core->move(direction, constrain(speed, 0, 255));

        String response = "{\"message\":\"all good\"}";

        request->send(200, "application/json", response);
    });


    m_server->begin();
}

void AppCore::move(Directions direction, std::uint8_t speed)
{
    switch(direction)
    {
        case Directions::STOP:
            m_left_motor->stop();
            m_right_motor->stop();
            break;
        case Directions::FORWARD:
            m_left_motor->forward(speed);
            m_right_motor->forward(speed);
            break;
        case Directions::BACKWARD:
            m_left_motor->reverse(speed);
            m_right_motor->reverse(speed);
            break;
        case Directions::LEFT:
            m_left_motor->forward(speed);
            m_right_motor->reverse(speed);
            break;
        case Directions::RIGHT:
            m_left_motor->reverse(speed);
            m_right_motor->forward(speed);
            break;
    }
}