#include <stdio.h>
#include <stdlib.h>
#define NB_VAL 5
/*
 * 
 */
int main(int argc, char** argv) {
    int nbcol = 1;
    int ligne;
    int colonne;
    for(ligne = 0; ligne < NB_VAL; ligne++){
        for(colonne = 0; colonne < nbcol; colonne++){
        printf("x");
    }
    nbcol += 1;
    printf("\n");
    }
    printf("\n");
    return (EXIT_SUCCESS);
}

