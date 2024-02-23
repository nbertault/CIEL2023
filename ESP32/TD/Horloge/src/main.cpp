#include <Arduino.h>
#include "esp32_snir.h"
#include "Clavier.h"
#include "Cadran.h"
#include "Horloge.h"

//uint8_t touches[3] = {BP1, BP2, BP3};
//
//Clavier leClavier(touches);
//Cadran *leCadran;
Horloge *uneHorloge;
/*
void setup() {
    Serial.begin(115200);
    leCadran = new Cadran;
}

void loop() {
    Clavier::TOUCHES_CLAVIER touche = leClavier.Scruter();
    
    switch (touche) {
        
        case Clavier::AUCUNE:
            leCadran->Afficher(0,0);
            break;
            
        case Clavier::MODE:
            leCadran->Afficher("MODE",touche);
            break;

        case Clavier::PLUS:
            leCadran->Afficher("PLUS",touche);
            break;

        case Clavier::MOINS:
            leCadran->Afficher("MOINS",touche);
            break;
    }
}
*/
void setup(){
    uneHorloge = new Horloge;
}
void loop(){
    
}