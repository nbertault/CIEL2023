#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>

/*
 * 
 */


/*--------------Partie1--------------
int main(int argc, char** argv)
{
    int ligne, colonne;
    InitialiserLeds();
    
    
    for(ligne = 0; ligne <=7; ligne++)
    {
        for(colonne = 0; colonne <=7; colonne++){
        Allumer(ligne,colonne,ORANGE);
        Allumer(colonne,ligne,ORANGE);
        }
        sleep(1);
        Effacer();
    }
    return (EXIT_SUCCESS);
}
 */

/*
int main(int argc, char** argv)
{
    int ligne, colonne;
    InitialiserLeds();
    
    
    for(ligne = 7; ligne >=0; ligne--)
    {
        for(colonne = 7; colonne >=0; colonne--){
        Allumer(ligne,colonne,ORANGE);
        Allumer(colonne,ligne,ORANGE);
        }
        sleep(1);
        Effacer();
    }
    return (EXIT_SUCCESS);
}
 */

int main(int argc, char** argv)
{
    int ligne, colonne;
    InitialiserLeds();


    for (ligne = 0; ligne <= 7; ligne++)
    {
        for (colonne = 0; colonne <= 7; colonne++)
        {
            Allumer(ligne, colonne, ORANGE);
            Allumer(colonne, ligne, ORANGE);
        }
        usleep(500000);
        Effacer();
    }
    for (ligne = 7; ligne >= 0; ligne--)
    {
        for (colonne = 7; colonne >= 0; colonne--)
        {
            Allumer(ligne, colonne, ORANGE);
            Allumer(colonne, ligne, ORANGE);
        }
        usleep(500000);
        Effacer();
    }
    return (EXIT_SUCCESS);
}