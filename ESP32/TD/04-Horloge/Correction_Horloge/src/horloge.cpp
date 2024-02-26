/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Horloge.cpp
 * Author: philippe
 * 
 * Created on 4 janvier 2024, 11:38
 */

#include "horloge.h"

/**
 * @brief Horloge::Horloge
 * @details     Constructeur de l'horloge initialise les attributs et les relations de composition
 * @param _nbMode       /// Nombre de modes de l'horloge
 * @param _resolution   /// Résolution de l'horloge par défaut 24
 */
Horloge::Horloge(const short _resolution, const short _nbMode) :
heures(0),
minutes(0),
resolution(_resolution),
nbMode(_nbMode),
mode(AUCUN_REGLAGE)
{
    leCadran = new Cadran;
    leClavier = new Clavier(touches);
    tempsPrec = millis();
}

/**
 * @brief Horloge::~Horloge
 * @details     Destructeur de la classe, libère la mémoire obtenu pour les compositions
 */
Horloge::~Horloge()
{
    delete leCadran;
    delete leClavier;
}

/**
 * @brief Horloge::AvancerHeures
 * @details     Avance les heures
 * @return      vrai si la résolution a été atteinte, faux sinon
 */
bool Horloge::AvancerMinutes()
{
    bool retour = false;
    if (++minutes == 60) 
    {
        minutes = 0;
        retour = true; 
    }
    return retour;
}

/**
 * @brief Horloge::AvancerMinutes
 * @details     Avance les minutes
 */
void Horloge::AvancerHeures()
{
    if (++heures == resolution)
        heures = 0;
}

/**
 * @brief Horloge::ReculerMinutes
 * @details     Recule les minutes
 */
void Horloge::ReculerMinutes()
{
    if (--minutes == -1)
        minutes = 59;
}

/**
 * @brief Horloge::ReculerHeures
 * @details     Recule les heures
 */
void Horloge::ReculerHeures()
{
    if (--heures < 0)
        heures = resolution - 1;
}

/**
 * @brief Horloge::ChangerMode
 * @details     Passe au mode suivant en tenant compte du nombre de mode
 */
void Horloge::ChangerMode()
{
    mode = static_cast<MODES_HORLOGE> ((mode + 1) % nbMode);
}

/**
 * @brief Horloge::ActualiserHeure
 * @details     Actualise les heures et les minutes si une minute est écoulée
 *              Réalise l'affichage sur l'écran. La fonction est non bloquante.
 */
void Horloge::ActualiserHeure()
{
    uint64_t valCourante = millis();
   
    if (valCourante - tempsPrec > MINUTE_ECOULEE) // à modifier pour aller plus vite pour le test, valeur en mili-secondes
    {
        tempsPrec = valCourante;
        if (AvancerMinutes())
            AvancerHeures();
        leCadran->Afficher(heures, minutes);
    }
    
}

/**
 * @brief Horloge::Controler
 * @details             Assure la gestion de l'horloge
 */
void Horloge::Controler()
{
    switch (mode)
    {
    case AUCUN_REGLAGE:

        if (toucheEnfoncee == Clavier::MODE)
            ChangerMode();
        else ActualiserHeure();
        break;

    case Horloge::REGLAGE_HEURES:
        switch (toucheEnfoncee)
        {
        case Clavier::PLUS:
            AvancerHeures();
            break;
        case Clavier::MOINS:
            ReculerHeures();
            break;
        case Clavier::MODE:
            ChangerMode();
            break;
        default:
            break;
        }
        leCadran->Afficher("HH", heures);
        break;

    case REGLAGE_MINUTES:
        switch (toucheEnfoncee)
        {
        case Clavier::PLUS:
            AvancerMinutes();
            break;
        case Clavier::MOINS:
            ReculerMinutes();
            break;
        case Clavier::MODE:
            ChangerMode();
            break;
        default:
            break;
        }
        leCadran->Afficher("MM", minutes);
        break;
    }
    toucheEnfoncee = leClavier->Scruter();
}

