#include <Arduino.h>
#include <SPI.h>
#include <MCP4141.h>

MCP4141 pot = MCP4141(8);

void setup() {
    Serial.begin(115200);
}

void loop() {
    for(int i=0; i < 127; i++){
        Serial.println(pot.increment());
        delay(100);
    }
    pot.setPos(0);
}