#include <Arduino.h>
#include "amodulator.h"

AMMODULATOR mod = AMMODULATOR(6, 8);

void setup() {
    Serial.begin(115200);
    mod.init(64);
}

void loop() {
    mod.setPos(random(0, 127));
    delay(10);
}