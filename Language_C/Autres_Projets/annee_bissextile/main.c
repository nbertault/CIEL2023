#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int annee = 2032;
    if(annee % 4 == 0 && annee % 100 != 0 && annee || 400 == 0){
        printf("%d est une année bissextile",annee);
    }
    else{
        printf("%d n'est pas une année bissextile",annee);
    }
    return (EXIT_SUCCESS);
}

