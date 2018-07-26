#include <Arduino.h>
#include <SPI.h>

class MCP4141 {
    public:
        MCP4141();
        MCP4141(uint8_t ce);            //Constructor
        uint8_t setPos(uint8_t p);
        uint8_t getPos();
        uint8_t setPercent(uint8_t p);
        uint8_t increment();
        uint8_t decrement();
    private:
        uint8_t chip_enable;
        uint8_t pos;
};

MCP4141::MCP4141(){
    ;;
}

MCP4141::MCP4141(uint8_t ce){
    SPI.begin();
    this->chip_enable = ce;
    this->pos = 0;
    pinMode(this->chip_enable, OUTPUT);
    this->setPos(127);
}

uint8_t MCP4141::setPos(uint8_t p){
    digitalWrite(chip_enable, LOW);
    SPI.transfer(0);
    SPI.transfer(p);
    digitalWrite(chip_enable, HIGH);
    digitalWrite(chip_enable, LOW);
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

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.println("Hello World!");
    delay(5000);
}