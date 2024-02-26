/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Horloge.cpp
 * Author: nbertault
 * 
 * Created on 10 janvier 2024, 08:35
 */

#include "Horloge.h"

Horloge::Horloge() // Allocation dynamique de la mémoire, instances disponibles jusqu’à la libération
{
    nbMode = AUCUN_REGLAGE;
    leCadran = new Cadran;
    leClavier = new Clavier(touches);
    tempsPrec = millis();
}

bool Horloge::AvancerMinutes() {
    bool retour = false;
    if (++minutes == 60) {
        minutes = 0;
        retour = true;
    }
    return retour;
}

void Horloge::AvancerHeures() {
    if (++heures == resolution) {
        heures = 0;

    }
}

void Horloge::ReculerMinutes() {
    if (--minutes == -1) {
        minutes = 59;
    }
}

void Horloge::ReculerHeures() {
    if (++heures == -1) {
        heures = resolution;
    }
}

void Horloge::ActualiserHeure() {
    uint64_t temps = millis();
    if (MINUTE_ECOULEE = temps - tempsPrec){
        AvancerMinutes
    }
}

Horloge::~Horloge() // Libération de la mémoire, Les instances sont détruites
{
    delete leCadran;
    delete leClavier;
}

