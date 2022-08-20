#include <unity.h>
#include <sensor.h>

void testSensor(void) {
    Sensor sensor = Sensor(10, 1.0);
    TEST_ASSERT_EQUAL(sensor.getValue(), 0);
    for (int i=0; i<10 ;i++) {
        sensor.sample();
    }
    TEST_ASSERT_LESS_OR_EQUAL(sensor.getValue(), 0);
}