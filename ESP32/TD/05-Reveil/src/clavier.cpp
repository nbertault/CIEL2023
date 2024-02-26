/* 
 * File:   Clavier.cpp
 * Author: philippe
 * 
 * Created on 3 janvier 2024, 15:12
 */

#include "clavier.h"

Clavier::Clavier(const uint8_t _lesBoutonsPoussoirs[], const int _nbPoussoirs) :
nbPoussoirs(_nbPoussoirs)
{
    lesBoutonsPoussoirs = new uint8_t[nbPoussoirs];
    for (int indice = 0; indice < nbPoussoirs; indice++)
    {
        lesBoutonsPoussoirs[indice] = _lesBoutonsPoussoirs[indice];
        pinMode(lesBoutonsPoussoirs[indice], INPUT);
    }
}

Clavier::~Clavier()
{
    delete[] lesBoutonsPoussoirs;
}

Clavier::TOUCHES_CLAVIER Clavier::Scruter()
{
    TOUCHES_CLAVIER retour = AUCUNE;
    for (int indice = 0; indice < nbPoussoirs; indice++)
    {
        if (digitalRead(lesBoutonsPoussoirs[indice]) == LOW)
            retour = static_cast<TOUCHES_CLAVIER> (indice);
        Serial.println(retour);
    }
    delay(200);

    return retour;
}


int t;