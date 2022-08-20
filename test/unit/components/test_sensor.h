#include <unity.h>
#include <sensor.h>
#include <analogsensor.h>

#include <Arduino.h>

void testSensor(void) {
    Sensor sensor = Sensor(10, 1.0);
    TEST_ASSERT_LESS_OR_EQUAL(sensor.getValue(), 0);
}

void testAnalogSensor(void) {
    AnalogSensor sensor = AnalogSensor(5, 1.0, A0);
    for (int i=0; i<5; i++) {
        sensor.sample();
    }
    TEST_ASSERT_LESS_OR_EQUAL(sensor.getValue(), 0);
}