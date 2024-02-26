/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Horloge.h
 * Author: philippe
 *
 * Created on 4 janvier 2024, 11:38
 */

#ifndef HORLOGE_H
#define HORLOGE_H

#include <Arduino.h>
#include "clavier.h"
#include "cadran.h"
#include "esp32_snir.h"

#define MINUTE_ECOULEE 60000



class Horloge {
public:
    Horloge(const short _resolution = 24, const short _nbMode = 3);
    ~Horloge();
    bool AvancerMinutes();
    void AvancerHeures();
    void ReculerMinutes();    
    void ReculerHeures();
    void ChangerMode();
    void ActualiserHeure();
    void Controler();      
   
    enum MODES_HORLOGE // déclaration des modes de l’horloge
    {	 
        AUCUN_REGLAGE,
        REGLAGE_HEURES,
        REGLAGE_MINUTES                                      
    };  
    
  protected:   
    int heures;
    int minutes;
    const int resolution;
    const short nbMode;
    MODES_HORLOGE mode;  
    
    uint64_t tempsPrec;  /// Valeur précédente du temps
    
    
    Clavier *leClavier ;
    const uint8_t touches[3] = {BP1,BP2,BP3};
    Clavier::TOUCHES_CLAVIER toucheEnfoncee;
    
    Cadran *leCadran;
};

#endif /* HORLOGE_H */

