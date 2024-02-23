/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Reveil.cpp
 * Author: nbertault
 * 
 * Created on 23 janvier 2024, 08:45
 */

#include "reveil.h"

Reveil::Reveil(const short  _resolution, const short _nbMode) :
Horloge(_resolution, _nbMode),
heureAlarme(0),
minuteAlarme(0),
alarme(false),
enAlarme(false) 
{
}

void Reveil::AvancerHeureAlarme()
{
    heureAlarme++;
    if(heureAlarme == resolution)
        heureAlarme = 0;
}

void Reveil::AvancerMinuteAlarme()
{
    minuteAlarme++;
    if(minuteAlarme == 60)
        minuteAlarme = 0;
}

void Reveil::ReculerHeureAlarme()
{
    heureAlarme--;
    if(heureAlarme < 0)
        heureAlarme = resolution-1;
}

void Reveil::ReculerMinuteAlarme()
{
    minuteAlarme--;
    if(minuteAlarme < 0)
        minuteAlarme = 59;
}

void Reveil::SurveillerAlarme()
{
    if(alarme == true)
        if(heureAlarme == heures && minuteAlarme == minutes)
        {
            laSonnerie.Declencher();
            enAlarme = true;
        }
}

void Reveil::Controler()
{
    Horloge::Controler();
    switch(mode)
    {
        case AUCUN_REGLAGE:
            SurveillerAlarme();
            if((toucheEnfoncee == Clavier::MOINS || toucheEnfoncee == Clavier::PLUS) && enAlarme)
            {
                laSonnerie.Arreter();
                enAlarme = false;
            }
            break;
        case REGLAGE_HEURES_ALARME:
            switch(toucheEnfoncee)
            {
                case Clavier::PLUS :
                    Serial.println("BP2");
                    AvancerHeureAlarme();
                    break;
                case Clavier::MOINS :
                    ReculerHeureAlarme();
                    break;
                case Clavier::MODE:
                    ChangerMode();
                    break;
            }
            leCadran->Afficher("HA",heureAlarme);
            break;
        case REGLAGE_MINUTES_ALARME:
            switch(toucheEnfoncee)
            {
                case Clavier::PLUS :
                    AvancerMinuteAlarme();
                    break;
                case Clavier::MOINS :
                    ReculerMinuteAlarme();
                    break;
                case Clavier::MODE:
                    ChangerMode();
                    break;
            }
            leCadran->Afficher("MA",minuteAlarme);
            break;
        case ACTIVATION_ALARME:
            switch(toucheEnfoncee)
            {
                case Clavier::PLUS :
                    alarme = true;
                    break;
                case Clavier::MOINS :
                    alarme = false;
                    break;
                case Clavier::MODE:
                    ChangerMode();
                    break;
            }
            if(alarme)
                leCadran->Afficher("Alarme", "ON");
            else
                leCadran->Afficher("Alarme", "OFF");
            break;
    }
}