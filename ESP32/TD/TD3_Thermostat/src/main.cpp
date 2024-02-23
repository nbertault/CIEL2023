#include <Arduino.h>
#include <SSD1306.h>
#include "thermostat.h"
#include "esp32_snir.h"
#include "afficheur.h"
#include "thermometre.h"

#define INTERVAL 5000 // mesure de la température toutes les 5s
#define HYSTERESIS 1
float temperature = 0;
float consigne = 0;
unsigned long precedent;

void setup() {
    InitialiserThermostat();
    InitialiserAfficheur();
    precedent = millis() - INTERVAL; // initialisation pour voir le temps écoulé
}

void loop() {
    int unite;
    int dixiemes;

    if (digitalRead(SW) == LOW) {
        consigne = FixerConsigne(consigne);
    } else {
        unsigned long courant = millis(); // attente de 5 secondes sans blocage
        if (courant - precedent >= INTERVAL) {
            precedent = courant;
            if (ObtenirTemperature(&unite, &dixiemes) == true)
                AfficherTemperature(unite, dixiemes);
            if (RegulerTemperature(consigne, unite + dixiemes / 10, HYSTERESIS) == true)
                digitalWrite(RL1, HIGH);
            else
                digitalWrite(RL1, LOW);
        }
    }
}