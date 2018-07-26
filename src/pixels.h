#ifndef pixels_h
#define pixels_h

#include <Adafruit_NeoPixel.h>

void showPercent(Adafruit_NeoPixel& pix, uint8_t per, uint32_t pri = 0x000A0000, uint32_t sec = 0x00006400){
    uint16_t num_pix = pix.numPixels();
    uint8_t n_per = map(per, 0, 100, 0, num_pix);
    Serial.println(n_per);
    for(int i = 0; i < num_pix; i++){
        pix.setPixelColor(i , pri);
    }
    pix.show();
    for(int i = 0; i < n_per; i++){
        pix.setPixelColor(i , sec);
        pix.show();
        delay(100);
    }

    
}

#endif