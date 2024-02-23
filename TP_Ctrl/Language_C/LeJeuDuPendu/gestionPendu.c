#include "gestionPendu.h"

const char *ObtenirMotAleatoire()
{
    static const char *listeMots[NB_MOTS] = {"bonjour", "maison", "noyau", "temps", "blond"};
    unsigned int valeurAleatoire;
    getrandom(&valeurAleatoire, sizeof (valeurAleatoire), 0);
    return listeMots[valeurAleatoire % NB_MOTS];
}

void InitialiserMot(char _motCourant[], const int _nbLettres)
{
    int indice;
    for(indice = 0; indice < _nbLettres; indice++)
    {
        _motCourant[indice] = '-';
    }
    _motCourant[indice] = '\0';
}

int PlacerLettre(const char _motATrouver[], char _motCourant[],const char _lettreProposee)
{
    int indice;
    int cpt = 0;
    int longueur = strlen(_motATrouver);
    for(indice = 0; _motATrouver[indice] != '\0'; indice++)  //for(indice = 0; indice < longueur; indice++)
    {
        if(_motATrouver[indice] == _lettreProposee){
            _motCourant[indice] = _lettreProposee;
            cpt++;
        }
    }
    return cpt;
}

bool VerifierProposition(const char _motATrouver[],const char _motCourant[])
{
    return strcmp(_motATrouver, _motCourant) == 0;
}

void AfficherPendu(const int _nbErreur)
{
    int indice;
char *pendu[8][6] = {
" \n", // pas d'erreur
" \n",
" \n",
" \n",
" \n",
" \n",

" \n", // 1 erreur
" \n",
" \n",
" \n",
" \n",
"/| \n",

" \n", // 2 erreurs
" | \n",
" | \n",
" | \n",
" | \n",
"/| \n",

" ____\n", // 3 erreurs
" | \n",
" | \n",
" | \n",
" | \n",
"/| \n",

" _____\n", // 4 erreurs
" | | \n",
" | \n",
" | \n",
" | \n",
"/| \n",

" _____\n", // 5 erreurs
" | | \n",
" | O \n",
" | \n",
" | \n",
"/| \n",
// tableau à compléter

" _____\n", // 6 erreurs
" | | \n",
" | O \n",
" |/|\\ \n",
" | \n",
"/| \n",

" _____ \n", // 7 erreurs
" | | \n",
" | O \n",
" |/|\\ \n",
" |/ \\ \n",
"/| \n",
};
for(indice = 0; indice < 6; indice ++){
    printf("%s",pendu[_nbErreur][indice]);
}
// code à ajouter ici pour l'affichage du pendu en fonction du nombre de tentatives infructueuses
}