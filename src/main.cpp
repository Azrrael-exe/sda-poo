#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "pixels.h"

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(36, 3, NEO_GRB + NEO_KHZ800);


void setup() {
    Serial.begin(115200);
    pixels.begin();
    for(int i = 0; i < 36; i++){
        pixels.setPixelColor(i, 0);
    }
    pixels.show(); // Initialize all pixels to 'off'
}

void loop() {
    uint8_t val = random(0, 100);
    showPercent(pixels, val);
}