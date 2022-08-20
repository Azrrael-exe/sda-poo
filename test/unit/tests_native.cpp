#include <unity.h>
#include "test_libs/test_circular.h"
#include "test_libs/test_sensor.h"

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(testCircularBuffer);
    RUN_TEST(testSensor);
    UNITY_END();
    return 0;
}