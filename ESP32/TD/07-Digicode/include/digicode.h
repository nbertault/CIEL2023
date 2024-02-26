/* 
 * File:   Digicode.h
 * Author: nbertault
 *
 * Created on 24 janvier 2024, 09:03
 */

#ifndef DIGICODE_H
#define DIGICODE_H
#include <Keypad.h>
#include <Arduino.h>
#include "esp32_snir.h"
#include "gache.h"

class Digicode {
public:
    
    enum ETATS_DIGICODE{
        NORMAL,
        MODIFICATION_CODE,
        CONFIRMATION
    };
    static const uint8_t LIGNES = 4;
    static const uint8_t COLONNES = 3;
    char touches[LIGNES * COLONNES] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9',
        '*', '0', '#'
    };
    //affectation des E/S GPIO aux L1,L2,L3,L4 du clavier
    uint8_t brochesEnLigne[LIGNES] = {26, 25, 33, 32};
    //affectation des E/S GPIO aux C1,C2,C3 du clavier
    uint8_t brochesEnColonne[COLONNES] = {15, 5, 4};
    
    Digicode();
    void FabriquerCodeCourant(const char _chiffre);
    void Signaler();
    void Controler();
    ~Digicode();
private:
    Keypad *leClavier;
    uint64_t tempoToucheDiese;
    ETATS_DIGICODE etat;
    Gache laGache;
    String codeCourant;
    String codeUtilisateur;
    String codeMemo;
    
};

#endif /* DIGICODE_H */

