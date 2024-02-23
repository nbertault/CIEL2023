#include <stdio.h>
#include <stdlib.h>
#define NB_ELEVES 5

/*
 * 
 */
int main(int argc, char** argv)
{
    double notes[NB_ELEVES] = {16, 14, 15.5, 12, 4};
    int indice;
    int cpt = 0;
    int min = notes[0];
    int max = notes[0];
    int somme = 0;
    for (indice = 0; indice <= NB_ELEVES - 1; indice++)
    {
        printf("L'élève numéro %d a eu la note %.1lf /20.\n",indice +1, notes[indice]);
        if (notes[indice] >= 10){
            cpt = cpt + 1; 
        }
        if (min > notes[indice]){
            min = notes[indice];
        }
        if(max < notes[indice]){
            max = notes[indice];
        }
        somme = somme + notes[indice];
    }
    printf("%d élèves ont obtenu une note >= 10\n",cpt);
    printf("La moyenne de la classe est : %.1f\n",somme/(float)NB_ELEVES);
    printf("La note la plus faible est : %d\n",min);
    printf("La note la plus élevée est : %d\n",max);
    return (EXIT_SUCCESS);
}

