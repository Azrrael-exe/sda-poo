#include <unity.h>
#include "test_libs/test_circular.h"

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_CircularBuffer);
    UNITY_END();
    return 0;
}