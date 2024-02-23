#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>
#include <unistd.h>

#define VERT 0x03E0
#define N NOIR
#define J JAUNE
#define V VERT
#define R ROUGE

/*
 * 
 */
int main(int argc, char** argv)
{
    int ligne, colonne;
    int touche;
    uint16_t image1[8][8] = {
        {N, J, J, J, J, J, J, N},
        {J, V, J, J, J, J, V, J},
        {J, J, J, J, J, J, J, J},
        {J, J, J, V, V, J, J, J},
        {J, J, J, J, J, J, J, J},
        {J, J, V, J, J, V, J, J},
        {N, J, J, V, V, J, J, N},
        {N, N, J, J, J, J, N, N},
    };
    uint16_t image2[8][8] = {
        {N, J, J, J, J, J, J, N},
        {J, R, J, J, J, J, R, J},
        {J, J, J, J, J, J, J, J},
        {J, J, J, R, R, J, J, J},
        {J, J, J, J, J, J, J, J},
        {J, J, J, R, R, J, J, J},
        {N, J, R, J, J, R, J, N},
        {N, N, J, J, J, J, N, N},
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
            touche = ScannerJoystick();
            sleep(1);
    }
    while (touche != KEY_ENTER);
    return (EXIT_SUCCESS);
}

