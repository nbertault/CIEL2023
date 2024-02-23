/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Clavier.h
 * Author: nbertault
 *
 * Created on 9 janvier 2024, 15:10
 */

#ifndef CLAVIER_H
#define CLAVIER_H

#include <Arduino.h>

class Clavier {
public:
    enum TOUCHES_CLAVIER
    {
        AUCUNE = -1,
        MODE,
        PLUS,
        MOINS,
    };
    Clavier(const uint8_t _lesBoutonsPoussoirs[], const int _nbPoussoirs = 3);
    ~Clavier();
    TOUCHES_CLAVIER Scruter();
private:
    uint8_t *lesBoutonsPoussoirs;
    int nbPoussoirs;
};

#endif /* CLAVIER_H */

