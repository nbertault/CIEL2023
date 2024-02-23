/* 
 * File:   main.c
A *  * Author: nbertault
 *
 * Created on 4 octobre 2023, 08:12
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char touche;
    int puissance = 128;
    printf("Appuyer sur une touche suivi de Entrée : ");
    touche = getchar();
    printf("Le code ASCII de %c en binaire : ", touche);
    do
    {
        if(touche >= puissance)
        {
            printf("1");
            touche -= puissance ;
        }
        else  printf("0");
        puissance /= 2;
    } while(puissance >= 1);
    printf("\n");
    return (EXIT_SUCCESS);
}