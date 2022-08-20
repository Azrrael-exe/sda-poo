#include <Arduino.h>
#include <sensor.h>

Sensor temperature_sensor = Sensor(20, 1);
Sensor preasure_sensor = Sensor(10, 2);

long timer = millis();

void setup(){
    Serial.begin(115200);
}

void loop(){
    if((millis() - timer) > 100) {
        temperature_sensor.sample();
        preasure_sensor.sample();
        timer = millis();
    }
    if (Serial.available()){
        Serial.println(temperature_sensor.getValue());
        Serial.println(preasure_sensor.getValue());
    }

}
