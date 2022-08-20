#include <unity.h>
#include "../components/test_circular.h"

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(testCircularBuffer);
    UNITY_END();
    return 0;
}