/* 
 * @file Plateau.h
 * @brief Déclaration de la classe Plateau
 * @author nbertault
 * @version 1.0
 * @date 14/02/2024
 */

#ifndef PLATEAU_H
#define PLATEAU_H
#include "flotte.h"

class Plateau {
public:
    
    Plateau(const string &_nomDuFichier);
    
    void AfficherGrille();
    void Tirer(const char _vertical, const int _horizontal, const bool _cible);
    void Jouer();
    
private:
    /// Tableau de la grille de jeu
    char grille[10][10];
    /// Définie la flotte de bateaux à couler
    Flotte laFlotte;
};

#endif /* PLATEAU_H */

