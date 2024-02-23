#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    char carLu;
    printf("Appuyez sur une touche suivi de la touche Entrée :");
    carLu = getchar();
    if(carLu >= 'A' && carLu <= 'Z'){
        printf("c'est une majuscule'");
    }
    else{
        if(carLu >= 'a' && carLu <='z'){
        printf("c'est une minuscule");
        }
        else{
            if(carLu >= '0' && carLu <='9'){
                printf("c'est un chiffre");
            }
            else{
                printf("c'est un caractère spécial");
            }
        }
    }
    return (EXIT_SUCCESS);
}

