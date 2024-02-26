/* 
 * File:   main.cpp
 * Author: nbertault
 *
 * Created on 13 février 2024, 15:00
 */

#include <cstdlib>
#include "bateau.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Bateau *leBateau;

    int horizontal;
    char vertical;
    ETATS_BATEAU resultat;
    do {
        leBateau = new Bateau("cuirasse", 'H', 5, 4, 'H');
        cin >> vertical >> horizontal;
        resultat = leBateau->Torpiller(vertical, horizontal);
        
    } while (resultat = COULE);

    return 0;
}

