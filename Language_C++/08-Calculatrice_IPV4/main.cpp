/* 
 * File:   main.cpp
 * Author: nbertault
 *
 * Created on 20 février 2024, 09:22
 */

#include <cstdlib>
#include <iostream>
#include "ipv4.h"

using namespace std;

void AfficherTableau(const unsigned char *tab) {
    for (int indice = 0; indice < 4; indice++) {
        cout << static_cast<int> (tab[indice]);
        if (indice < 3)
            cout << ".";
    }
    cout << endl;
}

void AfficherTableau(const unsigned char *tab);

int main() {
    unsigned char adresse[4] = {192, 172, 1, 155};
    unsigned char masque[4];
    unsigned char reseau[4];
    unsigned char diffusion[4];
    unsigned char premiere[4];
    unsigned char derniere[4];

    IPv4 uneAdresse(adresse, 11); // instanciation de la classe IPv4
    
    cout << "Adresse IPv4 : ";
    AfficherTableau(adresse);

    uneAdresse.ObtenirMasque(masque); // appel d'une méthode
    
    cout << "Masque : ";
    AfficherTableau(masque);
    
    uneAdresse.ObtenirAdresseReseau(reseau);
    
    cout << "Réseau : ";
    AfficherTableau(reseau);
    
    uneAdresse.ObtenirAdresseDiffusion(diffusion);
    
    cout << "Diffusion : ";
    AfficherTableau(diffusion);
    
    uneAdresse.ObtenirPremiereAdresse(premiere);
            
    cout << "Première adresse disponible : ";
    AfficherTableau(premiere);
    
    uneAdresse.ObtenirDerniereAdresse(derniere);
            
    cout << "Dernière adresse disponible : ";
    AfficherTableau(derniere);
    
    int hote = uneAdresse.CalculerNombreHote(masque);
            
    cout << "Nombre Hotes disponible : " << hote << endl;
    
    return 0;
}
