//#include <Arduino.h>
//#include "esp32_snir.h"
//#include "ecran.h"
//#include "serrure.h"
//
//
//
//void setup() {
//    ecran->AfficherMessage("Code :", 1);
//    pinMode(BP1, INPUT);
//    pinMode(BP2, INPUT);
//}
//
//void loop() {
//    if (digitalRead(BP1) == LOW) {
//        laSerrure->Verrouiller();
//        ecran->AfficherMessage("Porte Fermé");
//    }
//    if (digitalRead(BP2) == LOW) {
//        laSerrure->Deverouiller();
//        ecran->AfficherMessage("Porte Ouverte");
//    }
//}

#include <Arduino.h>
#include "coffre.h"

Coffre *leCoffre;

void setup() {
    leCoffre = new Coffre;
}

void loop() {
    leCoffre->Controler();
}