
/* 
 * File:   thermometre.h
 * Author: nbertault
 *
 * Created on 5 décembre 2023, 17:43
 */
#include <Arduino.h>
#include <OneWire.h>
#include "afficheur.h"
#include <DallasTemperature.h>
#include "esp32_snir.h"

#ifndef THERMOMETRE_H
#define THERMOMETRE_H

void InitialiserCapteurTemperature(void);
bool ObtenirTemperature(int *_temperature, int * _dixiemes, const int _numCapteur=0) ;

#endif /* THERMOMETRE_H */

