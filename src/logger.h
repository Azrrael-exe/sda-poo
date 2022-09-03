#ifndef LOGGER
#define LOGGER

#include <Arduino.h>

void loggerFormater(Stream &uart, uint8_t value){
    uart.println("Hello World");
    uart.println(value);
}

#endif