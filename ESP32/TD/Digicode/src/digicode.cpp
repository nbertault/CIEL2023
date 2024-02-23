/* 
 * File:   Digicode.cpp
 * Author: nbertault
 * 
 * Created on 24 janvier 2024, 09:03
 */

#include "digicode.h"

Digicode::Digicode() {
    leClavier = new Keypad(touches, brochesEnLigne, brochesEnColonne, LIGNES, COLONNES);
    codeUtilisateur = ('1', '2', '3', '4');
    codeCourant.clear();
    codeMemo.clear();
    etat = NORMAL;
    tempoToucheDiese = 0;
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
}

void Digicode::FabriquerCodeCourant(const char _chiffre) {
    if (codeCourant.length() < 4) {
        codeCourant[codeCourant.length()] = _chiffre;
    } else {
        for (int i = 0; i < 3; i++) {
            codeCourant[i] = codeCourant[i++];
        }
        codeCourant[3] = _chiffre;
    }
    Serial.println(codeCourant[1]);
}

void Digicode::Controler() {
    char touche = leClavier->getKey();
    if (isdigit(touche) > 0) {
        FabriquerCodeCourant(touche);
    }
//    else{
//        if(touche = '#'){
//            tempoToucheDiese = millis();
//        }
//        tempoToucheDiese = 0;
//    }
}

void Digicode::Signaler() {
    switch (etat) {
        case Digicode::NORMAL:
            digitalWrite(D1, LOW);
            digitalWrite(D2, LOW);
            break;
        case Digicode::MODIFICATION_CODE:
            digitalWrite(D1, HIGH);
            digitalWrite(D2, LOW);
            break;
            case Digicode::CONFIRMATION:
            digitalWrite(D1, HIGH);
            digitalWrite(D2, HIGH);
            break;
    }
}

Digicode::~Digicode() {
    delete leClavier;
}

