#include <Arduino.h>
#include "MotorControllerConfig.h"
#include "AppCore.h"

void setup() {
  Serial.begin(115200);
}

void loop() {
  static AppCore core(MotorControllerConfig{});
}