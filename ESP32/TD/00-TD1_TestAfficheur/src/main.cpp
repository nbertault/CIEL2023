#include <Arduino.h>
#include "afficheur.h"
#include "esp32_snir.h"

int temperature;
int dixieme;

void setup() {
    InitialiserAfficheur();
    pinMode(BP1, INPUT);
    pinMode(BP2, INPUT);
    pinMode(SW, INPUT);
    temperature = 0;
    dixieme = 0;
}

void loop() {

    

    if (digitalRead(SW) == HIGH) {

        if (digitalRead(BP1) == LOW) {
            temperature++;
        }
        if (digitalRead(BP2) == LOW) {
            temperature--;
        }
    }
    
    if (digitalRead(SW) == LOW) {

        if (digitalRead(BP1) == LOW) {
            dixieme++;
            if(dixieme > 9){
                dixieme = 0;
            }
        }
        if (digitalRead(BP2) == LOW) {
            dixieme--;
            if(dixieme < 0){
                dixieme = 9;
            }
        }
    }
    AfficherTemperature(temperature, dixieme);
    
    delay(200);
}