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
    uint16_t couleurs[8] = {ROUGE, VERT, BLEU, BLANC, JAUNE, ORANGE, MAGENTA, CYAN};

    InitialiserLeds();
    
    for (indice = 0; indice < 8; indice++)
    {
        Allumer(0,indice,couleurs[indice]);
    }
    return (EXIT_SUCCESS);
}

