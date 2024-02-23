/* 
 * File:   main.c
 * Author: nbertault
 *
 * Created on 12 décembre 2023, 16:26
 */

#include <stdio.h>
#include <stdbool.h>
#include "distributeur.h"

#define NB_BOISSONS 5
#define MONNAIE_ACCEPTEE 5
#define NB_PIECE 5

/*
 * 
 */
int main(int argc, char** argv)
{
    char* nomBoissons[NB_BOISSONS] = {"Café sucré", "Café au lait", "Chocolat", "Coca cola", "Orangina"};
    double prixBoissons[NB_BOISSONS] = {150, 150, 150, 100, 100};
    int valeurPieces[MONNAIE_ACCEPTEE] = {10, 20, 50, 100, 200};
    int stockPieces[MONNAIE_ACCEPTEE] = {NB_PIECE, NB_PIECE, NB_PIECE, NB_PIECE, NB_PIECE};
    int piecesRendues[255] = {0, 0, 0, 0, 0};
    int piecesIntroduites[255] = {0, 0, 0, 0, 0};
    int indice;

    do
    {
        int boisson = ChoisirBoisson(nomBoissons, prixBoissons); // Choix de la boisson
        float reste = prixBoissons[boisson] - EffectuerPayement(stockPieces, valeurPieces, prixBoissons[boisson], piecesIntroduites);
        bool rendue = false;
        if (reste != 0)
        {
            rendue = RendreMonnaie(stockPieces, -reste, valeurPieces, piecesRendues);
        }
        ServirBoisson(nomBoissons[boisson], piecesRendues, rendue, valeurPieces);
    }
    while (1);

    return (0);
}

