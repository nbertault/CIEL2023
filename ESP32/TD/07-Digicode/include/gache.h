/* 
 * File:   Gache.h
 * Author: nbertault
 *
 * Created on 24 janvier 2024, 08:06
 */

#ifndef GACHE_H
#define GACHE_H
#include <Arduino.h>
#include "esp32_snir.h"

class Gache {
public:
    Gache(const uint8_t _brocheRelais = RELAY_1, const int _delaiOuverture = 500);
    void Ouvrir();
    int delaiOuverture;
private:
    uint8_t brocheRelais;
};

#endif /* GACHE_H */

