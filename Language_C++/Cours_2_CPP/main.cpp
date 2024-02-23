
/* 
 * File:   main.cpp
 * Author: nbertault
 *
 * Created on 30 janvier 2024, 08:59
 */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string motCle;
    int valeur;

    ifstream fichier("config.txt");
    if (!fichier.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    }
    else 
    {
        do {
            fichier >> motCle >> valeur;
            if (fichier.good()) {
                cout << motCle << " " << valeur << endl;
            }

        } while (!fichier.eof());
    }
    return 0;
}