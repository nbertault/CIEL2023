/* 
 * @file    Bateau.cpp
 * @brief   Implémentation de la classe Bateau
 * @author  nbertault
 * @version 1.0
 * @date    14/02/2024
 */

#include "bateau.h"

/**
 * @brief Bateau::Bateau
 * @details Constructeur de la classe Bateau. Initialisaton des différentes variables. Allocation de la mémoire pour le tableau coque, mise à zéro de chaque case de celui-ci
 * @param _nom Nom du bateau
 * @param _vertical Coordonnée verticale de la proue du bateau
 * @param _horizontal Coordonnée horizontal de la proue du bateau
 * @param _taille Nombre de case occupée par le bateau
 * @param _sens Orientation du bateau, 'H' pour horizontale et 'V' pour verticale
 */

Bateau::Bateau(const string &_nom, const char _vertical, const int _horizontal, const int _taille, const char _sens) :
nom(_nom),
vertical(_vertical),
horizontal(_horizontal),
taille(_taille),
sens(_sens),
etatBateau(MANQUE) {
    coque = new int [_taille];
    for (int i = 0; i < _taille; i++) {
        coque[i] = 0;
    }
}

/**
 * @brief Bateau::~Bateau
 * Destructeur de la classe Bateau, Libère la mémoire
 */

Bateau::~Bateau() {
    delete [] coque;
}

/**
 * @brief Bateau::Torpiller
 * Envoyer une torpille sur un bateau
 * @param _vertical Coordonnée vertical de la torpille
 * @param _horizontal Coordonnée horizontal de la torpille
 * @return TOUCHE Si la torpille touche le bateau
 *         COULE  Si le bateau est TOUCHE sur toutes ses cases
 *         MANQUE Si la torpille n'a pas atteint le bateau
 */

Bateau::ETATS_BATEAU Bateau::Torpiller(const char _vertical, const int _horizontal) {
    ETATS_BATEAU retour = MANQUE;

    if (sens == 'V') {
        if (horizontal == _horizontal) {
            if (vertical <= _vertical && _vertical <= vertical + taille - 1) {
                if (coque[_vertical - vertical] != 1) {
                    coque[_vertical - vertical] = 1;
                    retour = TOUCHE;
                    if (etatBateau != COULE) {
                        etatBateau = TOUCHE;
                    }
                }
            }
        }
    }else
    {
        if (vertical == _vertical) {
            if (horizontal <= _horizontal && _horizontal <= horizontal + taille - 1) {
                if (coque[_horizontal - horizontal] != 1) {
                    coque[_horizontal - horizontal] = 1;
                    retour = TOUCHE;
                    if (etatBateau != COULE) {
                        etatBateau = TOUCHE;
                    }
                }
            }
        }
    }
    if(retour == TOUCHE){
        int nbTouches = 0;
        for(int i = 0; i < taille; i++){
            nbTouches += coque[i];
        }
        if(nbTouches == taille){
            retour = COULE;
            etatBateau = COULE;
        }
    }

    return retour;
}

/**
 * @brief Bateau::ObtenirNom
 * Renvoie le nom du bateau
 * @return Nom du bateau
 */
string Bateau::ObtenirNom() {
    return nom;
}

/**
 * @brief Bateau::ObtenirEtatBateau
 * Renvoie l'état du du bateau
 * @return TOUCHE Si le bateau est TOUCHE au moins une fois mais pas sur toute ses cases
 *         COULE  Si le bateau est TOUCHE sur toutes ses cases
 *         MANQUE Si le bateau n'est pas TOUCHE
 */

Bateau::ETATS_BATEAU Bateau::ObtenirEtatBateau() {
    return etatBateau;
}