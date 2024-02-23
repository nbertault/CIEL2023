/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Cadran.h
 * Author: nbertault
 *
 * Created on 9 janvier 2024, 15:45
 */

#ifndef CADRAN_H
#define CADRAN_H

#include <Arduino.h>
#include <SSD1306.h>
#include <string.h>
#include "esp32_snir.h"

class Cadran : public SSD1306 // Relation d’héritage
{
public:
    Cadran(const int16_t _dx = 20, const int16_t _dy = 16);
    void Afficher(const int _heures, const int _minutes);
    void Afficher(const String _chaine, const int _valeur);
private:
    int16_t dx; // Coordonnée en x du premier caractère à afficher dans le cadran
    int16_t dy; // Coordonnée en y du premier caractère à afficher dans le cadran
};
#endif // CADRAN_H

