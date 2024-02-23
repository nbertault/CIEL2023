/* 
 * @file    Flotte.cpp
 * @brief   Implémentation de la classe Flotte
 * @author  nbertault
 * @version 1.0
 * @date    14/02/2024
 */

#include "flotte.h"
/**
 * @brief Flotte::Flotte
 * Constructeur de la classe Flotte. Initialisation de la variables nbBateaux à zéro. Ouverture du fichier et copie des données dans les variables.
 * Allocation dynamique des différents bateaux
 * @param _nomDuFichier Nom du fichier à ouvrir et lire
 */
Flotte::Flotte(const string &_nomDuFichier) :
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

/**
 * @brief Flotte::~Flotte 
 * Destructeur de la classe Flotte, Libère la mémoire
 */

Flotte::~Flotte() {
    for (int i = 0; i < nbBateaux; i++) {
        if (lesBateaux[i] != nullptr) {
            delete lesBateaux[i];
        }
    }
}

/**
 * @brief Flotte::TirerSurLaFlotte
 * Verifie que la torpille touche un bateau de la flotte
 * @param _vertical Coordonnée verticale de la torpille
 * @param _horizontal Coordonnée horizontale de la torpille
 * @return TOUCHE Si la torpille touche un bateau
 *         MANQUE Si la torpille n'a pas atteint un bateau
 */

Bateau::ETATS_BATEAU Flotte::TirerSurLaFlotte(const char _vertical, const int _horizontal) {
    Bateau::ETATS_BATEAU retour = Bateau::MANQUE;
    int i = 0;
    do {
        if (lesBateaux[i] != nullptr) {
            retour = lesBateaux[i]->Torpiller(_vertical, _horizontal);
        }
        i++;
    } while (retour == Bateau::MANQUE && i < nbBateaux);
    return retour;
}

/**
 * @brief Flotte::VerifierEtatDeLaFlotte
 * Vérifie si les bateaux sont encore en jeu 
 * @return TOUCHE Si le bateau est TOUCHE sur une ou plusieurs cases
 *         COULE  Si le bateau est TOUCHE sur toutes ses cases
 *         MANQUE Si le bateau n'est pas TOUCHE
 */

Bateau::ETATS_BATEAU Flotte::VerifierEtatDeLaFlotte() {
    Bateau::ETATS_BATEAU retour = Bateau::MANQUE;
    Bateau::ETATS_BATEAU resultat = Bateau::MANQUE;
    int cpt = 0;
    for (int i = 0; i < nbBateaux; i++) {
        if (lesBateaux[i] != nullptr) {
            resultat = lesBateaux[i]->ObtenirEtatBateau();
            if (resultat != Bateau::COULE) {
                cpt++;
            }
            if (resultat == Bateau::TOUCHE) {
                retour = Bateau::TOUCHE;
            }
        }
    }
    if (cpt == nbBateaux) {
        retour = Bateau::COULE;
    }
    return retour;
}

/**
 * @brief Flotte::ObtenirNbBateaux
 * Vérifie le nombre de bateau encore en jeu
 * @return Nombre de bateaux encore en jeu
 */
int Flotte::ObtenirNbBateaux() const{
    return nbBateaux;
}