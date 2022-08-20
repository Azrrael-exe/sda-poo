#ifndef SENSOR
#define SENSOR

#include <stdint.h>
#include <circular.h>

class Sensor {
protected:
    float value;
    float scale;
    bool is_ready;
    uint8_t pin;
    CircularBuffer buffer;
public:
    Sensor(){};
    Sensor(uint8_t size, float scale);
    virtual void sample(){};
    float getValue();
};

#endif