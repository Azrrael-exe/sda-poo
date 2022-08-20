#include <unity.h>
#include "../components/test_circular.h"
#include "../components/test_sensor.h"

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(testAnalogSensor);
    RUN_TEST(testSensor);
    RUN_TEST(testCircularBuffer);
    UNITY_END();
    return 0;
}