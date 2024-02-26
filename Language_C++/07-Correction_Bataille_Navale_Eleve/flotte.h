/* 
 * @file Flotte.h
 * @brief Déclaration de la classe Flotte
 * @author nbertault
 * @version 1.0
 * @date 14/02/2024
 */

#ifndef FLOTTE_H
#define FLOTTE_H

#include "bateau.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

class Flotte {
public:
    
    Flotte(const string &_nomDuFichier);
    ~Flotte();
    
    Bateau::ETATS_BATEAU TirerSurLaFlotte(const char _vertical, const int _horizontal);
    Bateau::ETATS_BATEAU VerifierEtatDeLaFlotte();
    int ObtenirNbBateaux() const;
    
private:
    /// Représente le nombre de bateau maximum lors d'une partie
    static const int NB_BATEAUX_MAX = 5;
    /// Représente le nombre de bateau en jeu
    int nbBateaux;
    /// Adresse du tableau dynamique contenant chaque informations concernant les différents bateaux
    Bateau *lesBateaux[NB_BATEAUX_MAX];
    
};

#endif /* FLOTTE_H */

