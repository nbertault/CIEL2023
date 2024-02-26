/* 
 * File:   Jeu2048.cpp
 * Author: nbertault
 * 
 * Created on 31 janvier 2024, 08:54
 */

#include "jeu2048.h"

Jeu2048::Jeu2048()
{
    for (int i = 0; i < 4; i++)
    {
        for (int i2 = 0; i2 < 4; i2++)
        {
            grille[i][i2] = 0;
        }
    }
    srand(time(nullptr));
    PlacerNouvelleTuille();
}

void Jeu2048::ObtenirGrille(int _grille[][TAILLE])
{
    for (int i = 0; i < 4; i++)
    {
        for (int i2 = 0; i2 < 4; i2++)
        {
            _grille[i][i2] = grille[i][i2];
        }
    }
}

void Jeu2048::PlacerNouvelleTuille()
{
    int chiffre = (((rand() % 2) + 1) * 2);
    int largeur = rand() % 4;
    int longueur = rand() % 4;


    while (grille[longueur][largeur] != 0)
    {
        largeur = rand() % 4;
        longueur = rand() % 4;
    }

    grille[longueur][largeur] = chiffre;

}

void Jeu2048::Deplacer(char _direction)
{
    int ligne;
    int colonne;
    for (int indice = 0; indice < 4; indice++)
    {
        switch (_direction)
        {
        case 'G':
            for (ligne = 0; ligne < 4; ligne++)
            {
                for (colonne = 0; colonne < 3; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne + 1];
                        grille[ligne][colonne + 1] = 0;
                    }
                }
            }
            break;
        case 'D':
            for (ligne = 0; ligne < 4; ligne++)
            {
                for (colonne = 1; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne][colonne - 1];
                        grille[ligne][colonne - 1] = 0;
                    }
                }
            }
            break;
        case 'B':
            for (ligne = 1; ligne < 4; ligne++)
            {
                for (colonne = 0; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne - 1][colonne];
                        grille[ligne - 1][colonne] = 0;
                    }
                }
            }
            break;
        case 'H':
            for (ligne = 0; ligne < 3; ligne++)
            {
                for (colonne = 0; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == 0)
                    {
                        grille[ligne][colonne] = grille[ligne + 1][colonne];
                        grille[ligne + 1][colonne] = 0;
                    }
                }
            }
            break;
            // à poursuivre pour les autres cas
        }
    }
}

bool Jeu2048::Calculer(const char _direction)
{

    int ligne;
    int colonne;
    bool retour = false;
    for (int indice = 0; indice < 4; indice++)
    {
        switch (_direction)
        {
        case 'G':
            for (ligne = 0; ligne < 4; ligne++)
            {
                for (colonne = 0; colonne < 3; colonne++)
                {
                    if (grille[ligne][colonne] == grille[ligne][colonne + 1])
                    {
                        grille[ligne][colonne] = grille[ligne][colonne + 1] * 2;
                        grille[ligne][colonne + 1] = 0;
                        retour = true;
                    }
                }
            }
            break;
        case 'D':
            for (ligne = 0; ligne < 4; ligne++)
            {
                for (colonne = 1; colonne < 4; colonne++)
                {
                    if (grille[ligne][colonne] == grille[ligne][colonne - 1])
                    {
                        grille[ligne][colonne] = grille[ligne][colonne - 1] * 2;
                        grille[ligne][colonne - 1] = 0;
                        retour = true;
                    }
                }
            }
            break;
        case 'B':
            for (colonne = 0; colonne < 4; colonne++)
            {
                for (ligne = 1; ligne < 4; ligne++)
                {
                    if (grille[ligne][colonne] == grille[ligne - 1][colonne])
                    {
                        grille[ligne][colonne] = grille[ligne - 1][colonne] * 2;
                        grille[ligne - 1][colonne] = 0;
                        retour = true;
                    }
                }
            }
            break;
        case 'H':
            for (colonne = 0; colonne < 4; colonne++)
            {
                for (ligne = 0; ligne < 3; ligne++)
                {
                    if (grille[ligne][colonne] == grille[ligne + 1][colonne])
                    {
                        grille[ligne][colonne] = grille[ligne + 1][colonne] * 2;
                        grille[ligne + 1][colonne] = 0;
                        retour = true;
                    }
                }
            }
            break;

            // à poursuivre pour les autres cas
        }
    }
    return retour;
}




int Jeu2048::CalculerScore() {
    int somme =0;
    for (int colonne = 0; colonne < 4; colonne++)
            {
                for (int ligne = 0; ligne < 4; ligne++)
                {
                    somme += grille[ligne][colonne];
                }
    }
return somme;
}

ETATS_DU_JEU Jeu2048::RechercherFinDePartie() {
    ETATS_DU_JEU retour = EN_COURS;
    int place = 0;
    
    for (int colonne = 0; colonne < 4; colonne++)
            {
                for (int ligne = 0; ligne < 4; ligne++)
                {
                    if(grille[ligne][colonne] == 2048){
                        retour = GAGNE;
                    }
                    if(grille[ligne][colonne] != 0){
                        place++;
                    }
                }
            }
    if (place == TAILLE * TAILLE){
        retour = PERDU;
    }
return retour;
}


