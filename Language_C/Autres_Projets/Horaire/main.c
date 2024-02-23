#include <stdio.h>
#include <stdlib.h>
#define Prix 11.52

/*
 * 
 */
int main(int argc, char** argv)
{
    int volumeHeures = 36;
    if (volumeHeures <= 35)
    {
        printf("Le prix total est de %d€",volumeHeures * Prix);
    }
    else
    {
        if (volumeHeures >= 36 && volumeHeures <= 39)
        {
            printf("Le prix total est de %d€",volumeHeures - 35 * Prix * 1.2 + 403,2);
        }
        else
        {
            if (volumeHeures >= 40 && volumeHeures <= 45)
            {
                printf("Le prix total est de %d€",volumeHeures - 39 * Prix * 1.5 + 458,496);
            }
            else
            {
                printf("Le prix total est de %d€",volumeHeures - 45 * Prix * 1.8 + 582,912);
            }
        }
    }
    return (EXIT_SUCCESS);
}

