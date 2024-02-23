 #include <Arduino.h>
/* 
#include "esp32_snir.h"
#include "clavier.h"
#include "cadran.h"

uint8_t touches[] = {BP1, BP2, BP3};
Clavier leClavier(touches);
Cadran *leCadran;

void setup()
{
    Serial.begin(115200);
    leCadran = new Cadran;
}

void loop()
{
    Clavier::TOUCHES_CLAVIER laTouche = leClavier.Scruter();

    switch (laTouche)
    {
    case Clavier::MODE:
        Serial.println("Mode");
        leCadran->Afficher("Mode", laTouche);
        break;
    case Clavier::PLUS:
        Serial.println("Plus");
        leCadran->Afficher("Plus", laTouche);
        break;
    case Clavier::MOINS:
        Serial.println("Moins");
        leCadran->Afficher("Moins", laTouche);
        break;
    default:
        leCadran->Afficher(0, 0);
        break;
    }

}
*/

#include "reveil.h"

Reveil *unReveil;


/**
 * @brief setup
 * @details Réalise l'initialisation de l'horloge
 */
void setup()
{
      unReveil = new Reveil;
      Serial.begin(115200);
}

/**
 * @brief loop
 * @details Boucle infinie pour le contrôle de l'horloge
 */
void loop()
{
    unReveil->Controler();
    //uneHorloge->ActualiserHeure();
}

//#include "cadran.h"
//#include "esp32_snir.h"
//
//Cadran *leCadran;
//
//void setup()
//{
//    pinMode(BP1,INPUT);
//    pinMode(BP2,INPUT);
//    leCadran = new Cadran(15,10);
//}
//
//void loop()
//{
//    if(digitalRead(BP1) == LOW)
//        leCadran->Afficher("Alarme", "ON");
//    if(digitalRead(BP2) == LOW)
//        leCadran->Afficher("Alarme", "OFF");
//}

//#include "sonnerie.h"
//#include "esp32_snir.h"
//
//Sonnerie laSonnerie;
//
//void setup()
//{
//    pinMode(BP1,INPUT);
//    pinMode(BP2,INPUT);
//}
//
//void loop()
//{
//    if(digitalRead(BP1) == LOW)
//        laSonnerie.Declencher();
//    if(digitalRead(BP2) == LOW)
//        laSonnerie.Arreter();
//}