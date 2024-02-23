/*
 * File:   Plateau.cpp
 * Author: nbertault
 *
 * Created on 31 janvier 2024, 08:54
 */

#include "plateau.h"

Plateau::Plateau()
{
    score = 0;
    nbCoups = 0;
}

void Plateau::Afficher()
{
    int laGrille[TAILLE][TAILLE];
    int indice;

    system("clear");
    leJeu.ObtenirGrille(laGrille);
    cout << "| Score : " << score << " | Nombre de coups : " << nbCoups << " |" << endl;
    cout << endl;
    for (int ligne = 0; ligne < 4; ligne++)
    {
        cout << " +";
        for (indice = 0; indice < 4; indice++)
        {
            cout << setw(7) << setfill('-') << '+';

        }
        cout << endl << " |";
        for (indice = 0; indice < 4; indice++)
        {
            if (laGrille[ligne][indice] != 0)
                cout << setfill(' ') << setw(6) << laGrille[ligne][indice] << '|'; // affichage d'une ligne de la grille
            else
            {
                cout << setfill(' ') << setw(7) << '|'; // affichage d'une ligne de la grille
            }
        }
        cout << endl;
    }
    cout << " +";
    for (indice = 0; indice < 4; indice++)// affichage de la dernière ligne du tableau
        cout << setw(7) << setfill('-') << '+';

    cout << endl << endl << "F pour sortir du jeu" << endl;
    cout << "Votre déplacement : H(↑), B(↓), G(←), D(→) : " << endl; // affichage du texte sous le tableau
}

bool Plateau::JouerCoup()
{
    bool retour = false;
    char touche;
    cin >> touche;
    bool calcul;
    touche = toupper(touche);
    if (strchr("BHGD", touche) != nullptr)
    {
        nbCoups++;

        leJeu.Deplacer(touche);
        calcul = leJeu.Calculer(touche);
        leJeu.Deplacer(touche);
        leJeu.PlacerNouvelleTuille();
        score = leJeu.CalculerScore();
        Afficher();
    }
    if (touche == 'F')
        retour = true;
    return retour;
}

int Plateau::RechercherJoueur(const string &_pseudo)
{
    int i = 0;

    while (tabJoueurs[i] != _pseudo && i < nbJoueurs)
        i++;

    if (i == nbJoueurs)
    {
        i = -1;
    }

    return i;
}

void Plateau::TrierTableauJoueurs()
{
    int borne = nbJoueurs;
    bool tri = false;
    while (tri == false)
    {
        tri = true;
        for (int i = 0; i < borne - 1; i++)
        {
            if (tabJoueurs[i] < tabJoueurs[i + 1])
            {
                Joueur compteur = tabJoueurs[i];
                tabJoueurs[i] = tabJoueurs[i + 1];
                tabJoueurs[i + 1] = compteur;
                tri = false;
            }
        }
        borne--;
    }

    ifstream leFichier("joueurs.txt");
    if (!leFichier.is_open())
    {
        nbJoueurs = 0;
    }
    else
    {
        leFichier >> nbJoueurs;
        for (int i = 0; i < nbJoueurs; i++)
        {
            leFichier >> tabJoueurs[i];
        }
    }
    ofstream fichier("joueurs.txt");
    if (!fichier.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    }
    else
    {
        fichier << nbJoueurs << endl;
        for (int i = 0; i < nbJoueurs; i++)
        {
            fichier << tabJoueurs[i];
        }
    }
    fichier.close();
}

void Plateau::AfficherResultat()
{
    string pseudo;
    int duree;
    cout << "Quel est votre pseudo" << endl;
    cin >> pseudo;
    cout << '+' << setfill('-') << setw(16) << '+' << setw(12) << '+' << setw(12) << '+' << endl;
    for (int i = 0; i < nbJoueurs; i++)
    {
        tabJoueurs[i].ObtenirInfo(pseudo, score, duree);
        cout << '|' << setfill(' ') << setw(15) << left << pseudo << '|' << setw(11) << score << '|' << setw(11) << duree << '|' << endl;
    }
    cout << '+' << setfill('-') << right << setw(16) << '+' << setw(12) << '+' << setw(12) << '+' << endl;
}