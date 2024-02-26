/* 
 * File:   Bateau.h
 * Author: nbertault
 *
 * Created on 13 février 2024, 15:00
 */

#ifndef BATEAU_H
#define BATEAU_H
#include <string>
#include <fstream>
#include <iomanip>
#define TAILLE 10

using namespace std;

enum ETATS_BATEAU{
    MANQUE,
    TOUCHE,
    COULE
};

class Bateau {
public:
    
    Bateau(const string _nom, const char _vertical, const int _horizontal, const int taille, const char _sens = 'H');
    virtual ~Bateau();
    
    ETATS_BATEAU Torpiller(const char _vertical, const int _horizontal);
    string ObtenirNom();
    ETATS_BATEAU ObtenirEtatBateau();
    
private:

    string nom;
    char vertical;
    int horizontal;
    int taille;
    char sens;
    int coque[TAILLE];
    ETATS_BATEAU etatBateau;
};

#endif /* BATEAU_H */

