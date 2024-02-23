/* 
 * File:   gestionPendu.h
 * Author: nbertault
 *
 * Created on 28 novembre 2023, 08:10
 */

#ifndef GESTIONPENDU_H
#define GESTIONPENDU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>
#include <stdbool.h>
#define NB_MOTS 5
#define NB_MAX_LETTRES_PROPOSEES 50
#define TAILLE_MAX_MOTS 50

    const char *ObtenirMotAleatoire();

    void InitialiserMot(char _motCourant[], const int _nbLettres);

    int PlacerLettre(const char _motATrouver[], char _motCourant[], const char _lettreProposee);

    bool VerifierProposition(const char _motATrouver[], const char _motCourant[]);
#ifdef __cplusplus
}
#endif

#endif /* GESTIONPENDU_H */

