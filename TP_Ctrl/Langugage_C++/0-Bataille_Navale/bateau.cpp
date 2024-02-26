/* 
 * File:   Bateau.cpp
 * Author: nbertault
 * 
 * Created on 13 février 2024, 15:00
 */

#include "bateau.h"

Bateau::Bateau(const string _nom, const char _vertical, const int _horizontal, const int _taille, const char _sens) :
horizontal(_horizontal),
vertical(_vertical),
nom(_nom),
taille(_taille),
sens(_sens) {
    for (int i = 0; i < _taille; i++) {
        coque[i] = 0;
    }
    etatBateau = MANQUE;
}

Bateau::~Bateau() {
}

ETATS_BATEAU Bateau::Torpiller(const char _vertical, const int _horizontal) {
    int somme;
    int indice = 0;
    etatBateau = MANQUE;

    if (sens == 'H' && _vertical == vertical) {
        indice = _horizontal - horizontal;
        if(indice >= 0 && indice < taille){
            coque[indice] = 1;
            etatBateau = TOUCHE;
        }
    }
    
    if (sens == 'V' && _horizontal == horizontal) {
        indice = _vertical - vertical;
        if(indice > 0 && indice < taille){
            coque[indice] = 1;
            etatBateau = TOUCHE;
        }
    }
    
    for (int i = 0; i < taille; i++) {
        somme = coque[i];
    }
    
    if (somme == taille){
        etatBateau = COULE;
    }
        
    return etatBateau;
}

string Bateau::ObtenirNom() {
    return "ee";
}

ETATS_BATEAU Bateau::ObtenirEtatBateau() {
    return COULE;
}