/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: nbertault
 *
 * Created on 6 février 2024, 09:31
 */

#include <cstdlib>
#include "joueur.h"
#include "menu.h"
#include "gestionJoueurs.h"

using namespace std;

const int NB_MAX_JOUEURS = 20;

/*
 * 
 */
int main(int argc, char** argv)
{
    Menu leMenu("Menu.txt");
    int choix;
    Joueur tabJoueurs[NB_MAX_JOUEURS];
    int nbJoueurs = 0;
    string pseudo;
    int score;
    int duree;

    do
    {
        choix = leMenu.AfficherEtAttendreChoix();
        switch (choix)
        {
        case AJOUTER:
        {
            int pos;

            cout << "Pseudo score durée :";
            cin >> pseudo >> score >> duree;

            if (nbJoueurs > 0)
            {
                pos = RechercherJoueur(tabJoueurs, NB_MAX_JOUEURS, pseudo);

                if (pos != -1)
                {
                    tabJoueurs[pos].Actualiser(score, duree);
                }
                else
                {
                    tabJoueurs[nbJoueurs++] = Joueur(pseudo, score, duree);
                }
            }
            else
            {
                tabJoueurs[nbJoueurs++] = Joueur(pseudo, score, duree);
            }

            if (nbJoueurs > 1)
            {
                TrierTableauJoueurs(tabJoueurs, NB_MAX_JOUEURS);
            }

            Menu::EffacerEcran();

            break;
        }

        case VISUALISER:
        {
            Menu::EffacerEcran();
            cout << '+' << setfill('-') << setw(16) << '+' << setw(12) << '+' << setw(12) << '+' << endl;
            for (int i = 0; i < nbJoueurs; i++)
            {
                tabJoueurs[i].ObtenirInfo(pseudo, score, duree);
                cout << '|' << setfill(' ') << setw(15) << left << pseudo << '|' << setw(11) << score << '|' << setw(11) << duree << '|' << endl;
            }
            cout << '+' << setfill('-') << right << setw(16) << '+' << setw(12) << '+' << setw(12) << '+' << endl;

            break;
        }
        case CHARGER:
        {
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
            leFichier.close();
            break;
        }
        case SAUVEGARDER:
        {
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
            break;
        }

            
            return 0;
        }
    }while (choix != QUITTER);
}

