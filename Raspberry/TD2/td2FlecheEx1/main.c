#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>

/*
 * 
 */

int main(int argc, char** argv)
{
    int ligne;
    int colonne;
    InitialiserLeds();

    while (1)
    {
        for (ligne = 0; ligne <= 2; ligne++)
        {
            for (colonne = 0; colonne <= 2; colonne++)
            {
                if (ligne == 2 || colonne == 2 || ligne == colonne)
                {
                    Allumer(ligne, colonne, ORANGE);
                }
                else
                {
                    Allumer(ligne, colonne, NOIR);
                    Allumer(colonne, ligne, NOIR);
                }
            }
        }
        sleep(1);
        Effacer();
        for (ligne = 0; ligne <= 7; ligne++)
        {
            for (colonne = 0; colonne <= 7; colonne++)
            {
                if (ligne == 7 || colonne == 7 || ligne == colonne)
                {
                    Allumer(ligne, colonne, ORANGE);
                }
                else
                {
                    Allumer(ligne, colonne, NOIR);
                    Allumer(colonne, ligne, NOIR);
                }
            }
        }
        sleep(1);
        Effacer();
    }
    return (EXIT_SUCCESS);
}
