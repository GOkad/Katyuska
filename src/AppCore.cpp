#include <Arduino.h>
#include "AppCore.h"
#include "MotorControllerConfig.h"
#include "MotorController.h"

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

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
        String response = "Hello world";
        request->send(200, "text/html", response);
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