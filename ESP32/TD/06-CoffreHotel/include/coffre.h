/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Coffre.h
 * Author: nbertault
 *
 * Created on 23 janvier 2024, 17:33
 */

#ifndef COFFRE_H
#define COFFRE_H
#include <Keypad.h>
#include "ecran.h"
#include "serrure.h"
#include "esp32_snir.h"

class Coffre {
public:

    enum ETATS_DU_COFFRE {
        OUVERT,
        FERMEE
    };
    static const uint8_t LIGNES = 4;
    static const uint8_t COLONNES = 3;
    char touches[LIGNES * COLONNES] = {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9',
        '*', '0', '#'
    };
    //affectation des E/S GPIO aux L1,L2,L3,L4 du clavier
    uint8_t brochesEnLigne[LIGNES] = {26, 25, 33, 32};
    //affectation des E/S GPIO aux C1,C2,C3 du clavier
    uint8_t brochesEnColonne[COLONNES] = {15, 5, 4};
    Coffre();
    void Controler();
    ~Coffre();
private:
    Keypad *clavier;
    Ecran *ecran;
    Serrure *laSerrure;
};

#endif /* COFFRE_H */

