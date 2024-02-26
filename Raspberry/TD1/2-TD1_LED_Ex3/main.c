#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>
/*
 * 
 */
int main(int argc, char** argv)
{
    int ligne, colonne;
    InitialiserLeds();
    
    
    for(ligne = 0; ligne <=7; ligne++)
    {
        for(colonne = 0; colonne <=7; colonne++){
        Allumer(ligne,colonne,BLEU);
        }
        sleep(1);
    Effacer();
    }
    return (EXIT_SUCCESS);
}

