#include "chaines.h"

int CalculerLongueur(const char _laChaine[])
{
    int nbCar = 0;
    while (_laChaine[nbCar] != '\0')
        nbCar++;

    return nbCar;
}

int ComparerChaine(const char _ch1[], const char _ch2[])
{
    int nbCar = 0;
    while (_ch1[nbCar] != '\0' && _ch2[nbCar] != '\0' && _ch1[nbCar] == _ch2[nbCar])
        nbCar++;
    return (_ch1[nbCar] - _ch2[nbCar]);
}

int SupprimerEspace(char _chaine[])
{
    int lecture = 0;
    int ecriture = 0;
    while (_chaine[lecture] != '\0')
    {
        if (_chaine[lecture] != ' ')
        {
            _chaine[ecriture++] = _chaine[lecture];
        }
        lecture++;
    }
    _chaine[ecriture] = '\0';
    return (lecture - ecriture);
}

int RechercherPalindrome(const char _palin[])
{
    int res;
    int debut=0;
    int fin = CalculerLongueur(_palin);
    while (_palin[debut] == _palin[fin] && debut < fin)
    {
        debut++;
        fin--;
        res = 0;
    }
    if(_palin[debut] != _palin[fin]){
        res=1;
    }
    return (res);
}