#ifndef amodulator_h
#define amodulator_h

#include <Arduino.h>
#include <MCP4141.h>

class AMMODULATOR: public MCP4141{
    public:
        AMMODULATOR(uint8_t pwm, uint8_t p): MCP4141(p) {
            pwm_pin = pwm;
        }
        void init(uint8_t duty);
        void stop();
    private:
        uint8_t pwm_pin;
};

void AMMODULATOR::init(uint8_t duty=127){
    analogWrite(pwm_pin ,duty);
}

void AMMODULATOR::stop(){
    analogWrite(pwm_pin ,0);
}

#endif