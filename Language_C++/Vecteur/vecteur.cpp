/* 
 * File:   Vecteur.cpp
 * Author: nbertault
 * 
 * Created on 6 février 2024, 08:45
 */

#include "vecteur.h"

Vecteur::Vecteur() {
    x = 0;
    y = 0;
}

Vecteur::Vecteur(const int _x, const int _y){
    x = _x;
    y = _y;
}

Vecteur Vecteur::operator+(const Vecteur &_autre) {
    return Vecteur(x + _autre.x, y + _autre.y);
}

bool Vecteur::operator==(const Vecteur &_autre) {
    bool retour = false;
    if (x == _autre.x && y == _autre.y)
        retour = true;
    return retour;
}

Vecteur Vecteur::operator+=(const Vecteur &_autre) {
    return Vecteur(x += _autre.x, y += _autre.y);
}

Vecteur Vecteur::operator-(const Vecteur &_autre) {
    return Vecteur(x - _autre.x, y - _autre.y);
}

Vecteur Vecteur::operator-=(const Vecteur &_autre) {
    return Vecteur(x -= _autre.x, y -= _autre.y);
}

void Vecteur::Afficher() {
    cout << "Vecteur : (" << x << "," << y << ")" << endl;
}

ostream & operator << (ostream &_flux,const Vecteur &_autre)
{
_flux << "(" <<_autre.x << "," << _autre.y << ")" << endl ;
}
