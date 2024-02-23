/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Reveil.h
 * Author: nbertault
 *
 * Created on 23 janvier 2024, 08:45
 */

#ifndef REVEIL_H
#define REVEIL_H
#include "horloge.h"
#include "sonnerie.h"

class Reveil : public Horloge {
public:

    enum MODES_REVEIL 
    {
        REGLAGE_HEURES_ALARME = 3,
        REGLAGE_MINUTES_ALARME,
        ACTIVATION_ALARME
    };
    
    Reveil(const short _resolution = 24, const short _nbMode = 6);
    void AvancerHeureAlarme();
    void AvancerMinuteAlarme();
    void ReculerHeureAlarme();
    void ReculerMinuteAlarme();
    void SurveillerAlarme();
    void Controler();
private:
    int heureAlarme;
    int minuteAlarme;
    bool alarme;
    bool enAlarme;
    
    Sonnerie laSonnerie;
};

#endif /* REVEIL_H */

