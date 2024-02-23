#include <stdio.h>
#include <stdlib.h>
#define NB_ELEMENTS 5

/*
 * 
 */
int main(int argc, char** argv)
{
    int debut = 0;
    int tour = 0;
    int tableau[NB_ELEMENTS] = {5, 7, 2, 1, 4};
    int indice;
    int copie = 0;
    int min = tableau[0];
    while (tour != NB_ELEMENTS)
    {
        for (indice = debut; indice <= NB_ELEMENTS - 1; debut++)
        {
            copie = tableau[indice];
            for (indice = 0; indice <= NB_ELEMENTS - 1; indice++)
            {

                printf("%d ", tableau[indice]);

            }
            for (indice = debut; indice <= NB_ELEMENTS - 1; indice++)
            {
                if (tableau[indice] < tableau[min])
                {
                    min = indice;
                }
            }
            printf("\n");
            tableau[debut] = tableau[min];
            tableau[min] = copie;
            tour++;
        }
    }
    return (NB_ELEMENTS);
}

