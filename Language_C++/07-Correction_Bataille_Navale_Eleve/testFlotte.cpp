/* 
 * File:   testFlotte.cpp
 * Author: nbertault
 *
 * Created on 14 février 2024, 10:16
 */

#include <iostream>
#include "flotte.h"

using namespace std;

/*
 * 
 */
int main() {
    Flotte laFlotte("LaFlotte.txt");
    cout << "Nombre de bateaux : " << laFlotte.ObtenirNbBateaux();
    Bateau::ETATS_BATEAU resultat;
    bool sortie = false;
    char vertical;
    int horizontal;

    if (laFlotte.ObtenirNbBateaux() != 0) {
        do {
            cout << "Entrer les coordonnée de la torpille : ";
            cin >> vertical >> horizontal;
            resultat = laFlotte.TirerSurLaFlotte(vertical, horizontal);
            switch (resultat) {
                case Bateau::TOUCHE:
                    cout << endl << "Bateau touché" << endl;
                    cout << "Rejouer" << endl;
                    break;
                case Bateau::COULE:
                    cout << endl << "Bateau coulé" << endl;
                    if (laFlotte.VerifierEtatDeLaFlotte() != Bateau::COULE){
                        cout << endl << "Rejouer" << endl;
                    }else{
                        sortie= true;
                    }
                    break;
                case Bateau::MANQUE:
                    cout << endl << "Bateau manqué" << endl;
                    cout << "Rejouer" << endl;
                    break;
            }

        } while (sortie == false);
    }
    cout << endl << "fin de partie";
    return 0;
}