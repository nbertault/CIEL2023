#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "esp32_snir.h"
Adafruit_NeoPixel pixels(NB_PIXELS, BROCHE_RGB, NEO_RGB);

void setup() {
    pixels.begin();
}

void loop() {
    int valeurADC = analogRead(ADC_LDR);
    uint8_t couleur = map(valeurADC, 0, 4095, 0, 255);
    uint32_t valeur = couleur;
    valeur += couleur <<8;
    valeur += couleur <<16;
    pixels.fill(valeur, 0, 4);
    pixels.show();
    delay(500);
}