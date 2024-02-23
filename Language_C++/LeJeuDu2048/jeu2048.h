/* 
 * File:   Jeu2048.h
 * Author: nbertault
 *
 * Created on 31 janvier 2024, 08:54
 */

#ifndef JEU2048_H
#define JEU2048_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <future>
#include <math.h>
#include <time.h>
#define TAILLE 4

using namespace std;

enum ETATS_DU_JEU
    {
        EN_COURS,
        PERDU,
        GAGNE
    };

class Jeu2048
{
public:
    Jeu2048();
    void PlacerNouvelleTuille();
    bool Calculer(const char _direction);
    void Deplacer(char _direction);
    int CalculerScore();
    void ObtenirGrille(int _grille[TAILLE][TAILLE]);
    ETATS_DU_JEU RechercherFinDePartie();
private:
    int grille[TAILLE][TAILLE];
};

#endif /* JEU2048_H */

