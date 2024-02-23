/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Coffre.cpp
 * Author: nbertault
 * 
 * Created on 23 janvier 2024, 17:33
 */

#include "coffre.h"

Coffre::Coffre() {
    ecran = new Ecran;
    laSerrure = new Serrure;
    clavier = new Keypad(touches, brochesEnLigne, brochesEnColonne, LIGNES, COLONNES);
}

void Coffre::Controler() {
    char unetouche = clavier->getKey();
    if (unetouche != NO_KEY) {
        ecran->AfficherMessage(String(unetouche), 1);
    }
}

Coffre::~Coffre() {
    delete ecran;
    delete laSerrure;
    delete clavier;
}

