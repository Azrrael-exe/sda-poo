#include "MCP4141.h"

MCP4141::MCP4141(){
    ;;
}

MCP4141::MCP4141(uint8_t ce){
    SPI.begin();
    chip_enable = ce;
    pos = 0;
    pinMode(chip_enable, OUTPUT);
    digitalWrite(chip_enable, HIGH);
    setPos(127);
}

uint8_t MCP4141::setPos(uint8_t p){
    digitalWrite(chip_enable, LOW);
    SPI.transfer(0);
    SPI.transfer(p);
    digitalWrite(chip_enable, HIGH);
    pos = p;
    return pos;
};

uint8_t MCP4141::getPos(){
    return pos;
};

uint8_t MCP4141::setPercent(uint8_t p){
    uint8_t cal_val = uint8_t(128*((100-p)/100.0));
    setPos(cal_val);
    return pos;
}

uint8_t MCP4141::increment(){
    if(pos < 127){
        digitalWrite(chip_enable, LOW);
        SPI.transfer(4);
        digitalWrite(chip_enable, HIGH);
        pos+=1;
    }
    return pos;
}

uint8_t MCP4141::decrement(){
  if(pos > 0){
    digitalWrite(chip_enable, LOW);
    SPI.transfer(8);
    digitalWrite(chip_enable, HIGH);
    pos-=1;
  }
  return pos;
}