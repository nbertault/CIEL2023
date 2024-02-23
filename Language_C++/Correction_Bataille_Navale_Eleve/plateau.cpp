/* 
 * @file    Flotte.cpp
 * @brief   Implémentation de la classe Flotte
 * @author  nbertault
 * @version 1.0
 * @date    14/02/2024
 */

#include "plateau.h"

/**
 * @brief Plateau::Plateau
 * Constructeur de la classe Plateau
 * @param _nomDuFichier
 */
Plateau::Plateau(const string &_nomDuFichier) :
laFlotte(_nomDuFichier) {
    for (int ligne = 0; ligne < 10; ligne++)
        for (int colonne = 0; colonne < 10; colonne++)
            grille[ligne][colonne] = ' ';
}

void Plateau::AfficherGrille() {
    int ligne;
    int colonne;
    char lettre = 'A';

    system("clear");
    cout << ' ';
    for (colonne = 0; colonne < 10; colonne++) {
        cout << setw(4) << setfill(' ') << colonne + 1;
    }
    cout << endl;
    for (ligne = 0; ligne < 10; ligne++) {
        cout << "  ";
        for (colonne = 0; colonne < 10; colonne++) {
            cout << '+' << setw(4) << setfill('-');
        }
        cout << '+' << endl;
        cout << lettre++ << ' ';
        for (colonne = 0; colonne < 10; colonne++) {
            cout << '|' << setw(2) << setfill(' ') << grille[ligne][colonne] << ' ';
        }
        cout << '|' << endl;
    }
    cout << "  ";
    for (colonne = 0; colonne < 10; colonne++) {
        cout << '+' << setw(4) << setfill('-');
    }
    cout << '+' << endl;
}

void Plateau::Tirer(const char _vertical, const int _horizontal, const bool _cible) {
    if (_cible) {
        grille[_vertical - 'A'][_horizontal - 1] = 'X';
    } else {
        grille[_vertical - 'A'][_horizontal - 1] = '0';
    }
    AfficherGrille();
}

void Plateau::Jouer() {
    Bateau::ETATS_BATEAU torpille;
    bool sortie = false;
    char vertical;
    int horizontal;
    if (laFlotte.ObtenirNbBateaux() != 0) {
        cout << "Entrer les coordonnées de la torpille : ";
        do {
            cin >> vertical >> horizontal;
            torpille = laFlotte.TirerSurLaFlotte(vertical, horizontal);
            switch (torpille) {
                case Bateau::TOUCHE:
                    Tirer(vertical, horizontal, true);
                    cout << "Rejouer : ";
                    break;
                case Bateau::COULE:
                    Tirer(vertical, horizontal, true);
                    cout << "Bateau coulé... ";
                    if (laFlotte.VerifierEtatDeLaFlotte() != Bateau::COULE)
                        cout << "rejouer : ";
                    else
                        sortie = true;
                    break;
                case Bateau::MANQUE:
                    Tirer(vertical, horizontal, false);
                    cout << "Rejouer : ";
                    break;
            }
        } while (sortie == false);
    }
    cout << "fin de la partie !" << endl;
}
