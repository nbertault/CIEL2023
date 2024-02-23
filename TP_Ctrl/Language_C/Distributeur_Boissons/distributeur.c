#include "distributeur.h"
#include <stdio.h>
#include <stdbool.h>

int ChoisirBoisson(char* nomBoissons[NB_BOISSONS], double prixBoissons[NB_BOISSONS])
{
    int _indice;
    int _boisson;

    for (_indice = 0; _indice < NB_BOISSONS; _indice++)
    {
        printf("%d - %s (%.2lf €)\n", _indice + 1, nomBoissons[_indice], prixBoissons[_indice] / 100); // Affichage du message
    }

    printf("\n0 - Annuler\n\nVotre choix : ");
    scanf("%d", &_boisson);

    return _boisson - 1;
}

float EffectuerPayement(int stockPieces[MONNAIE_ACCEPTEE], int valeurPieces[MONNAIE_ACCEPTEE], float _prix, int piecesIntroduites[255])
{
    float argent_total = _prix;
    float argent_dep = 0;
    double _entree;
    int indice;

    do
    {
        printf("Prix : %.2lf\n", argent_total / 100);
        printf("Monnaie déposée : %.2lf\n", argent_dep / 100);
        printf("\n\n0 - Annuler\n");
        printf("Pièce : ");
        scanf("%lf", &_entree);

        for (indice = MONNAIE_ACCEPTEE - 1; indice >= 0; indice--)
        {
            if (_entree == valeurPieces[indice])
            {
                stockPieces[indice]++;
                piecesIntroduites[indice]++;
                argent_dep += _entree;
            }
        }

        if (_entree == 0)
        {
            argent_dep = 0;
            return argent_dep;
        }
    }
    while (argent_dep < argent_total && _entree != 0);

    return argent_dep / 100;
}

bool RendreMonnaie(int stockPiece[MONNAIE_ACCEPTEE], float montant, int valPiece[MONNAIE_ACCEPTEE], int piecesRendues[255])
{
    bool retour = true;
    int indice;
    for (indice = MONNAIE_ACCEPTEE - 1; indice >= 0; indice--)
    {
        if (valPiece[indice] <= montant && stockPiece[indice] > 0)
        {
            int nombrePieces = montant / (valPiece[indice] / 100);
            if (nombrePieces > stockPiece[indice])
            {
                nombrePieces = stockPiece[indice];
            }

            montant -= nombrePieces * (valPiece[indice] / 100);
            stockPiece[indice] -= nombrePieces;
            piecesRendues[indice] = nombrePieces;
        }
        indice--;
    }

    if (montant == 0)
    {
        retour = false;
    }

    return retour;
}

void ServirBoisson(char* nomBoissons, int piecesRendues[], bool rendue, int valeurPieces[MONNAIE_ACCEPTEE])
{
    printf("Boisson choisie : %s\n", nomBoissons);
    if (rendue)
    {
        for (int indice = MONNAIE_ACCEPTEE - 1; indice >= 0; indice--)
        {
            if (piecesRendues[indice] > 0)
            {
                printf("%d pièce(s) de %.2f€\n", piecesRendues[indice], valeurPieces[indice] / 100.0);
            }
        }
    }
    else
    {
        printf("Pas de monnaie à rendre\n");
    }
    printf("\n");
}