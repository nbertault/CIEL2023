/* 
 * File:   Gache.cpp
 * Author: nbertault
 * 
 * Created on 24 janvier 2024, 08:06
 */

#include "gache.h"

Gache::Gache(const uint8_t _brocheRelais, const int _delaiOuverture) :
brocheRelais(_brocheRelais),
delaiOuverture(_delaiOuverture)
{
    pinMode(brocheRelais, OUTPUT);
    pinMode(LED, OUTPUT);
    digitalWrite(brocheRelais, LOW);
    digitalWrite(LED, LOW);
}

void Gache::Ouvrir()
{
    digitalWrite(brocheRelais, HIGH);
    digitalWrite(LED, HIGH);
    delay(delaiOuverture);
    digitalWrite(brocheRelais, LOW);
    digitalWrite(LED, LOW);
}


