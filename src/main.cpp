#include <Arduino.h>
#include <analogsensor.h>

#include <logger.h>

AnalogSensor temperature_sensor = AnalogSensor(20, 0.5, A0);
AnalogSensor preasure_sensor = AnalogSensor(20, 7.0, A1);

long timer = millis();

void setup(){
    pinMode(A0,INPUT);
    pinMode(A1, INPUT);
    Serial.begin(115200);
}

void loop(){
    if((millis() - timer) > 100) {
        temperature_sensor.sample();
        preasure_sensor.sample();
        timer = millis();
    }
    if (Serial.available()){
        loggerFormater(Serial, temperature_sensor.getValue());
        Serial.println(preasure_sensor.getValue());
        while (Serial.available()) {
            Serial.read();
        }
    }
}
