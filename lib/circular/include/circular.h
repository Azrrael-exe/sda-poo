#ifndef CIRCULAR_BUFFER
#define CIRCULAR_BUFFER

class CircularBuffer {
protected:
    int in_index;
    int out_index;
    int* list;
    int size;
    int free_slots;
public:
    CircularBuffer(int size);
    bool add(int value);
    int remove();
    int inIndex();
    int outIndex();
    int freeSlots();
};

#endif