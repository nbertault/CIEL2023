#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv)
{
    char carLu;
    do
    {
        printf("Appuyez sur une touche suivi de la touche Entrée :\n");
        carLu = getchar();
        printf("La touche %c:\n", carLu);
        printf("Décimal :%d\nHéxadécimal: %#04X\n", carLu, carLu);
        if (carLu >= 'A' && carLu <= 'Z')
        {
            printf("C'est une majuscule\n");
        }
        else
        {
            if (carLu >= 'a' && carLu <= 'z')
            {
                printf("C'est une minuscule\n");
            }
            else
            {
                if (carLu >= '0' && carLu <= '9')
                {
                    printf("C'est un chiffre\n");
                }
                else
                {
                    printf("C'est un caractère spécial\n");
                }
            }
        }
    }
    while (carLu != 27);
    return (EXIT_SUCCESS);
}