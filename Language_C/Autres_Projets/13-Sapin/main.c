#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>
#include <unistd.h>

#define O ORANGE
#define J JAUNE
#define V 0x07E0
#define R ROUGE
#define B BLEU
#define M MAGENTA
#define N NOIR


/*
 * 
 */
int main(int argc, char** argv)
{
    int ligne, colonne;
    int touche;
    uint16_t image1[8][8] = {
        {N, N, N, J, J, N, N, N},
        {N, N, N, V, V, N, N, N},
        {N, N, V, V, V, V, N, N},
        {N, V, V, V, V, V, V, N},
        {N, N, M, V, V, M, N, N},
        {N, V, V, R, B, V, V, N},
        {V, V, V, V, V, V, V, V},
        {N, N, N, O, O, N, N, N},
    };
    uint16_t image2[8][8] = {
        {N, N, N, J, J, N, N, N},
        {N, N, N, V, V, N, N, N},
        {N, N, V, V, V, V, N, N},
        {N, V, V, V, V, V, V, N},
        {N, N, R, V, V, R, N, N},
        {N, V, V, B, M, V, V, N},
        {V, V, V, V, V, V, V, V},
        {N, N, N, O, O, N, N, N},
    };
    uint16_t image3[8][8] = {
        {N, N, N, J, J, N, N, N},
        {N, N, N, V, V, N, N, N},
        {N, N, V, V, V, V, N, N},
        {N, V, V, V, V, V, V, N},
        {N, N, B, V, V, B, N, N},
        {N, V, V, M, R, V, V, N},
        {V, V, V, V, V, V, V, V},
        {N, N, N, O, O, N, N, N},
    };
    

    InitialiserJoystick();
    InitialiserLeds();

    do
    {
        for (ligne = 0; ligne <= 7; ligne++)
        {
            for (colonne = 0; colonne <= 7; colonne++)
            {
                Allumer(ligne, colonne, image1[ligne][colonne]);
            }
        }
        sleep(1);
        for (ligne = 0; ligne <= 7; ligne++)
        {
            for (colonne = 0; colonne <= 7; colonne++)
            {
                Allumer(ligne, colonne, image2[ligne][colonne]);
            }
        }
        sleep(1);
        for (ligne = 0; ligne <= 7; ligne++)
        {
            for (colonne = 0; colonne <= 7; colonne++)
            {
                Allumer(ligne, colonne, image3[ligne][colonne]);
            }
        }
            touche = ScannerJoystick();
            sleep(1);
    }
    while (touche != KEY_ENTER);
    return (EXIT_SUCCESS);
}

