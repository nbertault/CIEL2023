/* 
 * File:   Flotte.cpp
 * Author: nbertault
 * 
 * Created on 13 février 2024, 15:58
 */

#include "flotte.h"

Flotte::Flotte(const string _nomDuFichier) :
nbBateaux(0) {
    ifstream fichier(_nomDuFichier);
    int indice = 0;
    if (!fichier.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier " << endl;
    } else {
        string nom;
        string position;
        int taille;
        char sens;
        char lettre;
        int chiffre;
        do {
            fichier >> nom >> position >> taille >> sens;
            if (fichier.good() && indice < NB_BATEAUX_MAX) {
                lettre = position.front();
                stringstream ss(position.substr(1));
                ss >> chiffre;
                lesBateaux[indice++] = new Bateau(nom, lettre, chiffre, taille, sens);
            }
        } while (!fichier.eof() && indice < NB_BATEAUX_MAX);
        nbBateaux = indice;
    }
    while (indice < NB_BATEAUX_MAX) {
        lesBateaux[indice++] = nullptr;
    }
}

Flotte::~Flotte() {
    for (int i = 0; i < NB_BATEAUX_MAX; i++) {


        if (lesBateaux[i] != nullptr) {
//            delete Bateau[i];
        }
    }
}

