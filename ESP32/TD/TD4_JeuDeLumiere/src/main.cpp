#include "jeuxDeLumiere.h"
#include <Arduino.h>
#include "esp32_snir.h"
#include <Adafruit_NeoPixel.h>



void setup(){
    InitialiserJeuxDeLumiere();
}

void loop(){
    FixerCouleurBase(1);
    FixerNuance(0);
    delay(500);
}