#include "jeuxDeLumiere.h"

Adafruit_NeoPixel spot(NB_PIXELS, BROCHE_RGB, NEO_RGB);

void InitialiserJeuxDeLumiere(void) {
    spot.begin();
    pinMode(BP1, INPUT);
    pinMode(BP2, INPUT);
    pinMode(BP3, INPUT);

    spot.clear();
    spot.show();
}

void FixerCouleurBase(int _numLED) {
    int valeurADC = analogRead(ADC_LDR);
    uint8_t couleur = map(valeurADC, 0, 4095, 0, 255);
    uint32_t valeur = 0;
    
    if (digitalRead(BP1) == LOW) {
        valeur = couleur << 16;
    }
    if (digitalRead(BP2) == LOW) {
        valeur = couleur << 8;
    }
    if (digitalRead(BP3) == LOW) {
        valeur = couleur;
    }
    spot.setPixelColor(_numLED, valeur);
    spot.show();
}

void FixerNuance(int _numLED){
    uint32_t valeur = spot.getPixelColor(0);
    
    uint8_t rouge = valeur & 0x00FF0000;
    uint8_t vert = valeur & 0x0000FF00 ;
    uint8_t bleu = valeur & 0x000000FF ;
    
    int valeurADC = analogRead(ADC_LDR);
    
    if (digitalRead(BP1) == LOW) {
        rouge = map(valeurADC, 0, 4095, 0, 255);
    }
    if (digitalRead(BP2) == LOW) {
        vert = map(valeurADC, 0, 4095, 0, 255);
    }
    if (digitalRead(BP3) == LOW) {
        bleu = map(valeurADC, 0, 4095, 0, 255);
    }
    valeur = (rouge << 16) + (vert << 8) + bleu;
    spot.setPixelColor(_numLED, valeur);
    spot.show();
}