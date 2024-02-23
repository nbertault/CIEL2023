#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5

/*
 * 
 */
int main(int argc, char** argv)
{
    int chiffre = 1;
    int ligne;
    int colonne;
    int nbzero = 0;
    int nbcolonne = TAILLE;
    for (ligne = 0; ligne <= TAILLE /2 ; ligne++)
    {
        for(colonne = 0 ; colonne < nbzero ; colonne++)
        {
            printf("0\t");
        }
        colonne=0;
        for(colonne = 0 ; colonne < nbcolonne ; colonne++)
        {
            printf("%d\t", chiffre);
            chiffre++;
            
        };
        for(colonne = 0 ; colonne < nbzero ; colonne++)
        {
            printf("0\t");
        }
        printf("\n");
        nbzero++;
        nbcolonne -= 2;
    }
    return (EXIT_SUCCESS);
}

