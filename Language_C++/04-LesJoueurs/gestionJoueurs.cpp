#include "gestionJoueurs.h"

int RechercherJoueur(const Joueur * _tab, const int _nb, const string &_pseudo)
{
    int i = 0;

    while (_tab[i] != _pseudo && i < _nb)
        i++;

    if (i == _nb)
    {
        i = -1;
    }

    return i;
}

void TrierTableauJoueurs(Joueur * _tab, const int _nb)
{
    int borne = _nb;
    bool tri = false;
    while (tri == false)
    {
        tri = true;
        for (int i = 0; i < borne - 1; i++)
        {
            if (_tab[i] < _tab[i + 1])
            {
                Joueur compteur = _tab[i];
                _tab[i] = _tab[i + 1];
                _tab[i + 1] = compteur;
                tri = false;
            }
        }
        borne--;
    }
}