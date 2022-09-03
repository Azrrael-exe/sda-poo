#include <Arduino.h>
#include <analogsensor.h>

void AnalogSensor::sample() {
    this->is_ready = true;
    this->buffer.add(analogRead(this->pin));
}
