#ifndef SENSOR
#define SENSOR

#include <stdint.h>
#include <circular.h>

class Sensor {
private:
    float value;
    float scale;
    bool is_ready;
    uint8_t pin;
    CircularBuffer buffer;
public:
    Sensor(){};
    Sensor(uint8_t size, float scale);
    void sample();
    float getValue();
};

#endif