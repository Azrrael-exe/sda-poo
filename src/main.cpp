#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <ArduinoJson.h>
#include "pixels.h"

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(36, 3, NEO_GRB + NEO_KHZ800);


void setup() {
    Serial.begin(115200);
    pixels.begin();
    pixels.show(); // Initialize all pixels to 'off'
}

void loop() {
    if(Serial.available() > 0){
        StaticJsonBuffer<200> jsonBuffer;
        String inp = Serial.readStringUntil('\n');
        JsonObject& req = jsonBuffer.parseObject(inp);
        if(req.success()){
            if(req.containsKey("function")){
                char* function;
                function = req["function"];
                if(String(function) == "set"){
                    showPercent(pixels, req.get<uint8_t>("value"));
                }
            }
        }
    }
}