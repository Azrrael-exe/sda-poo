#include <Arduino.h>
#include <llp.h>

#include <analogsensor.h>
#include <button.h>

#define TEMPERATURE_SENSOR_ID 0xA6
#define PREASURE_SENSOR_ID 0x9C
#define BUTTON_INPUT 0x02

AnalogSensor temperature_sensor = AnalogSensor(20, 0.5, A0);
AnalogSensor preasure_sensor = AnalogSensor(20, 7.0, A1);

long timer = millis();

Button button = Button(BUTTON_INPUT, false, 100);

void setup(){
    pinMode(A0,INPUT);
    pinMode(A1, INPUT);
    pinMode(BUTTON_INPUT, INPUT);
    Serial.begin(115200);
}

void loop(){
    if((millis() - timer) > 100) {
        temperature_sensor.sample();
        preasure_sensor.sample();
        timer = millis();
    }
    if (Serial.available() or button.getState()){
        DataPack payload;
        payload.addData(
            TEMPERATURE_SENSOR_ID, 
            uint16_t(temperature_sensor.getValue())
        );
        payload.addData(
            PREASURE_SENSOR_ID, 
            uint16_t(preasure_sensor.getValue())
        );
        payload.write(Serial);
        while (Serial.available()) {
            Serial.read();
        }
    }
}
