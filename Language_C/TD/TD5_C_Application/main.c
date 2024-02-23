#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main(int argc, char** argv)
{
    char login[] = "toto";
    char mdp[] = "toto";
    char entree1[30];
    char entree2[30];
    
    printf("Entrez votre login : ");
    scanf("%s", entree1);
    printf("Entrez votre mot de passe : ");
    scanf("%s", entree2);
    
    if (strcmp(entree1, login) != 0)
    {
        printf("Login éronné");
    }
    
    if (strcmp(entree2, mdp) != 0)
    {
        printf("Mot de passe éronné");
    }
    
    if (strcmp(entree2, mdp) == 0 && strcmp(entree1, login) == 0){
        printf("Bienvenue");
    }
        
    return (EXIT_SUCCESS);
}

