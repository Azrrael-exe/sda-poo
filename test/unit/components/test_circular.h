#include <unity.h>
#include <circular.h>


void testCircularBuffer(void) {
    CircularBuffer test_add = CircularBuffer(4);
    // A add
    TEST_ASSERT_TRUE(test_add.add(1));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),3);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),0);

    // B add
    TEST_ASSERT_TRUE(test_add.add(2));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),2);
    TEST_ASSERT_EQUAL(test_add.inIndex(),2);
    TEST_ASSERT_EQUAL(test_add.outIndex(),0);

    float sum = 0;
    for (uint8_t i=0; i < 2; i++) {
        sum += test_add.getValueFromIndex(i);
    }

    TEST_ASSERT_EQUAL_FLOAT(test_add.mean(), float(sum) / 2);

    // C add
    TEST_ASSERT_TRUE(test_add.add(3));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),1);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),0);

    // D add
    TEST_ASSERT_EQUAL(test_add.remove(),1);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),2);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),1);

    // E remove
    TEST_ASSERT_EQUAL(test_add.remove(),2);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),3);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),2);

    // F remove
    TEST_ASSERT_TRUE(test_add.add(4));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),2);
    TEST_ASSERT_EQUAL(test_add.inIndex(),0);
    TEST_ASSERT_EQUAL(test_add.outIndex(),2);

    // G add
    TEST_ASSERT_TRUE(test_add.add(5));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),1);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),2);

    // H remove
    TEST_ASSERT_EQUAL(test_add.remove(),3);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),2);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),3);

    // I remove
    TEST_ASSERT_EQUAL(test_add.remove(),4);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),3);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),0);

    // J remove
    TEST_ASSERT_EQUAL(test_add.remove(),5);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),4);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),1);


    // K remove
    TEST_ASSERT_EQUAL(test_add.remove(),-1);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),4);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),1);

    TEST_ASSERT_TRUE(test_add.add(1));
    TEST_ASSERT_TRUE(test_add.add(2));
    TEST_ASSERT_TRUE(test_add.add(3));
    TEST_ASSERT_TRUE(test_add.add(4));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),0);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),1);

    // sobre escribir
    TEST_ASSERT_TRUE(test_add.add(5));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),0);
    TEST_ASSERT_EQUAL(test_add.inIndex(),2);
    TEST_ASSERT_EQUAL(test_add.outIndex(),2);

    sum = 0;
    for (uint8_t i=0; i < 4; i++) {
        sum += test_add.getValueFromIndex(i);
    }

    TEST_ASSERT_EQUAL_FLOAT(test_add.mean(), float(sum) / 4);

    TEST_ASSERT_TRUE(test_add.add(6));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),0);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),3);

    TEST_ASSERT_EQUAL(test_add.remove(),3);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),1);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),0);

    TEST_ASSERT_EQUAL(test_add.remove(),4);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),2);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),1);
}