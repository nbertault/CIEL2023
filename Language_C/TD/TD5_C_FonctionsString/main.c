#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */

/*Exercice 2*//*
int main(int argc, char** argv)
{
    char ecriture[255];
    size_t taille;
    scanf("%s",ecriture);
    taille = strlen(ecriture);
    printf("Longueur : %d\n",taille);
    
    return (EXIT_SUCCESS);
}
*/

/*Exercice 3*/
int main(int argc, char** argv)
{
    char texte1[122];
    char texte2[122];
    char fusion[255];
    char *ptr = texte1;
    int espace = 0;
    size_t taille1;
    size_t taille2;
    fgets(texte1, sizeof(texte1), stdin);
    texte1[strlen(texte1)-1] =  '\0';
    scanf("%s", texte2);

    if (strcmp(texte1, texte2) == 0)
    {
        printf("Les chaines sont identiques.\n");
    }
    else
    {
        if (strcmp(texte1, texte2) < 0)
        {
            printf("%s est lexicalement plus petites que %s.\n", texte1, texte2);
        }
        else
        {
            printf("%s est lexicalement plus grandes que %s.\n", texte1, texte2);
        }
    }

    /*Exercice 4*/

    if (strstr(texte1, texte2) == NULL)
    {
        printf("%s ne contient pas %s\n", texte1, texte2);
    }
    else
    {
        printf("%s contient %s\n", texte1, texte2);
    }

    /*Exercice 5*/
    ptr = strchr(texte1, ' ');
    while(ptr != NULL)
    {
        espace++;
        ptr = strchr(ptr+1, ' ' );
    }
    printf("Il y a %d espace dans %s\n", espace, texte1);
    
    /*Exercice 6*/
    printf("Il y a %d mots dans %s\n", espace+1, texte1);
    
    /*Exercice 7*/
    strcpy(fusion, texte1);
    strcat(fusion, " ");
    strcat(fusion, texte2);
    printf("La fusion des caractère donne %s\n",fusion);
    return (EXIT_SUCCESS);
}
