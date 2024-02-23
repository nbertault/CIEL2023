/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Horloge.h
 * Author: nbertault
 *
 * Created on 10 janvier 2024, 08:35
 */

#ifndef HORLOGE_H
#define HORLOGE_H

#include "Cadran.h"
#include "Clavier.h"

class Horloge {
public:
    enum MODE_HORLOGES
    {
        AUCUN_REGLAGE,
        REGLAGE_HEURES,
        REGLAGE_MINUTES,
    };
    Horloge();
    ~Horloge();
    bool AvancerMinutes();
    void AvancerHeures();
    void ReculerMinutes();
    void ReculerHeures();
    void ActualiserHeure();
private:
    int nbMode = AUCUN_REGLAGE;
    int heures = 0;
    int minutes = 0;
    int resolution;
    MODE_HORLOGES mode;
    uint64_t tempsPrec = millis();
    const uint8_t touches[3] = {BP1,BP2,BP3};
    const int MINUTE_ECOULEE = 1000;
    Clavier::TOUCHES_CLAVIER toucheEnfoncee;
    Clavier *leClavier; // déclaration des pointeurs en tant qu’attributs de la classe
    Cadran *leCadran; // Les instances seront utilisables par toutes les méthodes de la classe
    
};



#endif /* HORLOGE_H */

