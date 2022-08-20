#include <Arduino.h>
#include <analogsensor.h>

void AnalogSensor::sample() {
    this->buffer.add(analogRead(this->pin));
}
