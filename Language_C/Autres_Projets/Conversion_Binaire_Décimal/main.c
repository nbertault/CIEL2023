#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    char carLu;
    int bits;
    int total = 0;
    int somme = 128;
    printf("Entrer 8 bits.\n");
    for (bits = 0; bits < 8; bits++)
    {
        do
        {
            carLu = getchar();
        }
        while (carLu != '1' && carLu != '0');
        if (carLu == '1')
        {
            total = total + somme;
        }
        else
        {
        }
        somme = somme / 2;
    }
    printf("Votre octet est égal à %d en décimal.\n", total);
    return (EXIT_SUCCESS);
}

