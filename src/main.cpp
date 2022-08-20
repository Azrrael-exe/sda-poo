#include <Arduino.h>
#include <circular.h>

CircularBuffer buffer = CircularBuffer(10);

void setup(){
    Serial.begin(115200);
}

void loop(){ 
    for(int i=0; i < 10; i++){
        buffer.add(i);
        Serial.println(buffer.freeSlots());
        delay(1000);
    }
}
