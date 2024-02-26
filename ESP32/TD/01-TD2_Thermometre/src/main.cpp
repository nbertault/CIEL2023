#include <Arduino.h>
#include <OneWire.h>
#include "afficheur.h"
#include "thermometre.h"
#include <DallasTemperature.h>
#include "esp32_snir.h"
int temperature;
int dixiemes;

void setup(){
    InitialiserCapteurTemperature();
    InitialiserAfficheur();
}

void loop(){
    ObtenirTemperature(&temperature,&dixiemes);
    AfficherTemperature(temperature,dixiemes);
    delay(5000);
}