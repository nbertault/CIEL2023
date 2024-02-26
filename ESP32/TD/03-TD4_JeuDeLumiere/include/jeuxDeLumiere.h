/* 
 * File:   jeuxDeLumiere.h
 * Author: nbertault
 *
 * Created on 13 décembre 2023, 08:56
 */

#ifndef JEUXDELUMIERE_H
#define JEUXDELUMIERE_H

#include "esp32_snir.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

void InitialiserJeuxDeLumiere(void);

void FixerCouleurBase(int _numLED);

void FixerNuance(int _numLED);

#endif /* JEUXDELUMIERE_H */

