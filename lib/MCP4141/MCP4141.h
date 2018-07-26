
#ifndef MCP4141_h
#define MCP4141_h

#include <Arduino.h>
#include <SPI.h>

class MCP4141 {
    public:
        MCP4141();
        MCP4141(uint8_t ce);            //Constructor
        uint8_t setPos(uint8_t p);
        uint8_t getPos();
        uint8_t setPercent(uint8_t p);
        uint8_t increment();
        uint8_t decrement();
    private:
        uint8_t chip_enable;
        uint8_t pos;
};

#endif