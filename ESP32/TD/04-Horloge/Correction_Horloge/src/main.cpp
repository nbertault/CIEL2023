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

#include "horloge.h"

Horloge *uneHorloge;


/**
 * @brief setup
 * @details Réalise l'initialisation de l'horloge
 */
void setup()
{
      uneHorloge = new Horloge;
      Serial.begin(115200);
}

/**
 * @brief loop
 * @details Boucle infinie pour le contrôle de l'horloge
 */
void loop()
{
    uneHorloge->Controler();
    //uneHorloge->ActualiserHeure();
}