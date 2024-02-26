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
    int touche;
    InitialiserLeds();
    InitialiserJoystick();
    do
    {
        for (ligne = 0;ligne <= 7; ligne++)
        {
            for (colonne = 0; colonne <= ligne; colonne++)
            {
                Allumer(ligne, colonne, BLEU);
                Allumer(colonne, ligne, BLEU);
            }
            usleep(200000);
            Effacer();
        }
        touche=ScannerJoystick();
    }
    while (touche != KEY_ENTER);
    return (EXIT_SUCCESS);
}
