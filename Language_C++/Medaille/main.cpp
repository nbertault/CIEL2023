/* 
 * File:   main.cpp
 * Author: nbertault
 *
 * Created on 30 janvier 2024, 09:13
 */

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string nomDuFichier;

    cout << "Entrer le nom du fichier à lire : ";
    cin >> nomDuFichier;

    int gold;
    int argent;
    int bronze;
    string pays;

    ofstream fichier("tableau_medaille.txt");
    ifstream leFichier(nomDuFichier.c_str());
    
    fichier << "+" << setfill('-') << setw(18) << "+" << setw(8) << "+" << setw(8) << "+" << setw(8) << "+" << endl;
    if (!fichier.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    } 
    else {
        if (!leFichier.is_open()) {
            cerr << "Erreur lors de l'ouverture du fichier" << endl;
        } 
        else {

            do {
                leFichier >> pays >> gold >> argent >> bronze;

                if (leFichier.good()) {

                    fichier << "|" << " " << setfill(' ') << setw(16) << left << pays << "|" << setw(7) << gold << "|" << setw(7) << argent << "|" << setw(7) << bronze << "|" << endl;

                }

            } while (!leFichier.eof());
        }
    }
    fichier << setfill('-') << setw(18) << "+" << setw(8) << "+" << setw(8) << "+" << setw(8) << "+" << "+" << endl;
    fichier.close;
    return 0;
}

