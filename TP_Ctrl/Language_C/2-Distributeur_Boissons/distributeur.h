#ifndef DISTRIBUTEUR_H
#define DISTRIBUTEUR_H

#include <stdio.h>
#include <stdbool.h>
#include "main.c"

#ifdef __cplusplus
extern "C" {
#endif

    int ChoisirBoisson(char* nomBoissons[NB_BOISSONS], double prixBoissons[NB_BOISSONS]);

    float EffectuerPayement(int stockPieces[MONNAIE_ACCEPTEE], int valeurPieces[MONNAIE_ACCEPTEE], float prix, int piecesIntroduites[255]);

    bool RendreMonnaie(int stockPiece[MONNAIE_ACCEPTEE], float montant, int valPiece[MONNAIE_ACCEPTEE], int piecesRendues[255]);

    void ServirBoisson(char* nomBoissons, int piecesRendues[], bool rendue, int valeurPieces[MONNAIE_ACCEPTEE]);


#ifdef __cplusplus
}
#endif

#endif /* DISTRIBUTEUR_H */

