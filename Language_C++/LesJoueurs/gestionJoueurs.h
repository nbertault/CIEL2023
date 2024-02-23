/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   gestionJoueurs.h
 * Author: nbertault
 *
 * Created on 6 février 2024, 17:02
 */

#include "joueur.h"

using namespace std;

#ifndef GESTIONJOUEURS_H
#define GESTIONJOUEURS_H

int RechercherJoueur(const Joueur * _tab, const int _nb, const string &_pseudo);
void TrierTableauJoueurs(Joueur * _tab, const int _nb);

#endif /* GESTIONJOUEURS_H */

