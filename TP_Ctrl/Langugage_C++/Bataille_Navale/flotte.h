/* 
 * File:   Flotte.h
 * Author: nbertault
 *
 * Created on 13 février 2024, 15:58
 */

#ifndef FLOTTE_H
#define FLOTTE_H

#include "bateau.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class Flotte {
public:

    Flotte(const string _nomDuFichier);
    ~Flotte();

//    Bateau::ETATS_BATEAU TirerSurLaFlotte(const char _vertical, const int _horizontal);
//    Bateau::ETATS_BATEAU VerifierEtatDeLaFlotte();
    int ObtenirNbBateaux() const;
    
private:
    static const int NB_BATEAUX_MAX = 5;
    int nbBateaux;
    Bateau *lesBateaux[NB_BATEAUX_MAX];
};

#endif /* FLOTTE_H */

