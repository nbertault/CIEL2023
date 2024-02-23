/* 
 * File:   thermostat.h
 * Author: nbertault
 *
 * Created on 12 décembre 2023, 15:27
 */

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <Arduino.h>
#include <SSD1306.h>
#include "esp32_snir.h"
#include "afficheur.h"
#include "thermometre.h"

void InitialiserThermostat(void);

float FixerConsigne(float);

bool RegulerTemperature(float _consigne, float _temp, int _hysteresis);

#endif /* THERMOSTAT_H */

