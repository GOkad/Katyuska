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
    m_right_motor{std::make_unique<MotorController>(0,2)},
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

    m_server->on("/update", HTTP_GET, [](AsyncWebServerRequest *request){
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


        String response = "{\"message\":\"all good\"}";

        request->send(200, "application/json", response);
    });


    m_server->begin();
}

void AppCore::test_movement()
{
    // Move forward
    Serial.println("Move forward");
    m_left_motor->forward();
    m_right_motor->forward();
    delay(1000);

    // Move right
    Serial.println("Move right");
    m_left_motor->reverse();
    m_right_motor->forward();
    delay(1000);

    // Move left
    Serial.println("Move left");
    m_left_motor->forward();
    m_right_motor->reverse();
    delay(1000);

    // Move Backward
    Serial.println("Move backward");
    m_left_motor->reverse();
    m_right_motor->reverse();
    delay(1000);

    Serial.println("Stop");
    m_left_motor->stop();
    m_right_motor->stop();
    delay(1000);

}