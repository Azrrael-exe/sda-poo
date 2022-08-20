#ifndef ANALOGSENSOR
#define ANALOGSENSOR

#include <sensor.h>

class AnalogSensor: public Sensor {
private:
    uint8_t pin;
public:
    AnalogSensor(uint8_t size, float scale, uint8_t pin):Sensor(size, scale){
        this->pin = pin;
    }
    void sample();
};

#endif