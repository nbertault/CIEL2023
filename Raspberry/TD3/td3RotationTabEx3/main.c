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
    uint16_t chenille[8] = {ROUGE, VERT, BLEU, BLANC, JAUNE, ORANGE, MAGENTA, CYAN};

    InitialiserLeds();
    
    while (1)
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
        }
        usleep(500000);
    }
    return (EXIT_SUCCESS);
}