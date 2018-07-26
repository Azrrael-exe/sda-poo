#include <SPI.h>
#include <Arduino.h>
#include <MCP4141.h>

MCP4141 pot = MCP4141(8);

void setup() {
    Serial.begin(115200);
}

void loop() {
    for(int i=0; i<127; i++){
        pot.setPos(i);
        delay(100);
    }
}