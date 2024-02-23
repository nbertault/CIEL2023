/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Sonnerie.h
 * Author: nbertault
 *
 * Created on 23 janvier 2024, 08:30
 */

#ifndef SONNERIE_H
#define SONNERIE_H
#include <Arduino.h>
#include "esp32_snir.h"

class Sonnerie {
public:
    Sonnerie(const uint8_t _broche = D1);
    void Declencher();
    void Arreter();
private:
    const uint8_t broche;

};

#endif /* SONNERIE_H */

