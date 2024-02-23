/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Joueur.h
 * Author: nbertault
 *
 * Created on 6 février 2024, 09:31
 */

#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Joueur
{
public:
    Joueur(const string _pseudo, const int _score = 0, const int _duree = 0);
    Joueur();
    void Actualiser(const int _nouveauScore, const int _duree);
    void ObtenirInfo(string &_pseudo, int &_score, int &_duree);
    bool operator<(const Joueur &_autre) const;
    bool operator!=(const string &_pseudo) const;
    friend ostream & operator<<(ostream &_flux, const Joueur &_joueur);
    friend istream & operator>>(istream &_flux, Joueur &_joueur);
private:
    string pseudo;
    int score;
    int duree;


};

#endif /* JOUEUR_H */

