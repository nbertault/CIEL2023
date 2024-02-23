/* 
 * File:   Vecteur.h
 * Author: nbertault
 *
 * Created on 6 février 2024, 08:45
 */

#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>

using namespace std;

class Vecteur {
public:
    Vecteur(const int _x, const int _y); // ce premier constructeur initialise x et y avec les paramètres
    Vecteur(); // celui-ci initialise x et y à 0
    Vecteur operator+(const Vecteur &_autre);
    bool operator==(const Vecteur &_autre);
    Vecteur operator+=(const Vecteur &_autre);
    Vecteur operator-(const Vecteur &_autre);
    Vecteur operator-=(const Vecteur &_autre);
    void Afficher();
    friend ostream & operator << (ostream &_flux,const Vecteur &_autre);
private:
    int x;
    int y;
};
#endif // VECTEUR_H

