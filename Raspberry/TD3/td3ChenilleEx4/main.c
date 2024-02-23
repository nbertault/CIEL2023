#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>
#include <unistd.h>

/*
 * 
 */
int main(int argc, char** argv)
{

    int indice;
    uint16_t aux;
    uint16_t couleurs[8] = {ROUGE, VERT, BLEU, BLANC, JAUNE, ORANGE, MAGENTA, CYAN};
    uint16_t chenille[8];
    int touche;
    
    InitialiserJoystick();
    InitialiserLeds();

    for (indice = 0; indice < 8; indice++)
    {
        chenille[indice] = couleurs[indice];
        Allumer(0, indice, chenille[indice]);
    }

    do
    {
        aux = chenille[0];
        for (indice = 0; indice < 7; indice++)
        {
            chenille[indice] = chenille[indice + 1];
        }
        chenille[indice] = aux;
        for (indice = 0; indice < 8; indice++)
        {
            Allumer(0, indice, chenille[indice]);
            Allumer(indice, 7, chenille[indice]);
            Allumer(7, indice, chenille[7 - indice]);
            Allumer(indice, 0, chenille[7 - indice]);
        }
        touche = ScannerJoystick();
        sleep(1);
    }
    while (touche != KEY_ENTER);
    return (EXIT_SUCCESS);
}