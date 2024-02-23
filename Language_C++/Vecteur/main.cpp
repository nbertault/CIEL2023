/* 
 * File:   main.cpp
 * Author: nbertault
 *
 * Created on 6 février 2024, 08:45
 */


#include "vecteur.h"

int main() {
    Vecteur va(4, 4);
    Vecteur vb(4, 1);
    Vecteur resultat;

    resultat = va + vb;
    cout << "Vecteur : " << resultat;

    resultat += va;
    cout << "Vecteur : " << resultat;

    resultat = va - vb;
    cout << "Vecteur : " << resultat;

    resultat -= va;
    cout << "Vecteur : " << resultat;

    if (va == vb)
        cout << "les vecteurs sont identiques" << endl;
    else
        cout << "va est différent de vb" << endl;

    return 0;
}

