/* 
 * File:   afficheur.h
 * Author: nbertault
 *
 * Created on 5 décembre 2023, 15:37
 */

#include <Arduino.h>
#include <SSD1306.h>
#include <fonts.h>

#ifndef AFFICHEUR_H
#define AFFICHEUR_H

void InitialiserAfficheur(void);
void AfficherTemperature(const int,const int);

#endif /* AFFICHEUR_H */

