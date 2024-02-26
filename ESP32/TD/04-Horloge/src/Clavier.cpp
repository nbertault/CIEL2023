/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Clavier.cpp
 * Author: nbertault
 * 
 * Created on 9 janvier 2024, 15:10
 */

#include "Clavier.h"

Clavier::Clavier(const uint8_t _lesBoutonsPoussoirs[], const int _nbPoussoirs) :
nbPoussoirs(_nbPoussoirs) {
    if (nbPoussoirs > 0) {
        lesBoutonsPoussoirs = new uint8_t[nbPoussoirs];
        for (int indice = 0; indice < nbPoussoirs; indice++) {
            lesBoutonsPoussoirs[indice] = _lesBoutonsPoussoirs[indice];
            pinMode(lesBoutonsPoussoirs[indice], INPUT);
        }
    } else
        lesBoutonsPoussoirs = nullptr;
}

Clavier::~Clavier() {
    delete[] lesBoutonsPoussoirs;
}

Clavier::TOUCHES_CLAVIER Clavier::Scruter() {
    TOUCHES_CLAVIER retour = AUCUNE;
    for (int indice = 0; indice < nbPoussoirs; indice++) {
        if (digitalRead(lesBoutonsPoussoirs[indice]) == LOW) {
            retour = static_cast<TOUCHES_CLAVIER> (indice);
        }
    }
    delay(200);
    return retour;
}

