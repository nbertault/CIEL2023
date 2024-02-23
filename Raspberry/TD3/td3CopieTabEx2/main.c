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
    uint16_t chenille[8];
    
    InitialiserLeds();
    
    for(indice = 0; indice < 8; indice++)
    {
        chenille[indice] = couleurs[indice];
        Allumer(0,indice,chenille[indice]);
    }
    return (EXIT_SUCCESS);
}

