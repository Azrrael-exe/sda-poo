#include <sensor.h>
#include <stdlib.h> 

Sensor::Sensor(uint8_t size, float scale) {
    this->value = 0;
    this->is_ready = false;
    this->scale = scale;
    this->buffer = CircularBuffer(size);
}

// void Sensor::sample() {
//     this->is_ready = true;
//     int sample = rand() % 1024;
//     this->buffer.add(sample);
// }

float Sensor::getValue() {
    if (this->is_ready) {
        return this->buffer.mean() * this->scale;
    }   
    return value;
}
