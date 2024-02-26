/* 
 * File:   main.c
 * Author: nbertault
 *
 * Created on 28 novembre 2023, 08:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestionPendu.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    char motRecherche[TAILLE_MAX_MOTS]; // mot à deviner
    char motCourant[TAILLE_MAX_MOTS];
    char historique[NB_MAX_LETTRES_PROPOSEES] = {0}; // lettres déjà proposées
    int cptPropositions = 0; // compteur de proposition effectuée
    int nbErreur = 0; // nombre de tentative infructueuses
    bool fin = false;
    int trouve;
    char lettre;
    bool finPartie = false;
    do
    {
        strncpy(motRecherche, ObtenirMotAleatoire(), TAILLE_MAX_MOTS - 1);
        InitialiserMot(motCourant, strlen(motRecherche));

        AfficherPendu(nbErreur);
        printf("%s \n", motRecherche);
        printf("%s \n", motCourant);
        printf("Proposer une lettre : ");
        do
        {
            memset(historique, '\0', NB_MAX_LETTRES_PROPOSEES);
            scanf(" %c", &lettre); // Saisie de la lettre en évitant les '\n' intempestifs.
            printf("\033[2J\033[1;1H"); // Pour effacer la console
            trouve = PlacerLettre(motRecherche, motCourant, lettre);
            if (trouve == 0)
            {
                nbErreur++;
            }
            AfficherPendu(nbErreur);
            printf("Mot recherché : %s\n", motCourant);
            historique[cptPropositions++] = lettre;
            printf("Historique des lettres proposées : %s\n", historique);
            if (nbErreur == 7 || VerifierProposition(motRecherche, motCourant) == true)
            {
                fin = true;
            }
            else
            {
                printf("Proposer une lettre : ");
            }
        }
        while (nbErreur < 7 && fin == false);
        if (nbErreur == 7)
        {
            printf("vous avez perdu... le mot recherché était : %s\n", motRecherche);
        }
        else
        {
            printf("Bravo vous avez trouvé le mot caché en %d proposition\n", cptPropositions); // Afficher le message attendu en cas de victoire
        }
        printf("Voulez-vous quitter o/n ? ");
        scanf("%c", &lettre);

    }
    while (lettre != 'o' || lettre != 'O');
    return (EXIT_SUCCESS);
}

