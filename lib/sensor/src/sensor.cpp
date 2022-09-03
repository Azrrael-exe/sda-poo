#include <sensor.h>
#include <stdlib.h> 

Sensor::Sensor(uint8_t size, float scale) {
    this->value = 0;
    this->is_ready = false;
    this->scale = scale;
    this->buffer = CircularBuffer(size);
}

float Sensor::getValue() {
    if (this->is_ready) {
        return this->buffer.mean() * this->scale;
    }   
    return value;
}
