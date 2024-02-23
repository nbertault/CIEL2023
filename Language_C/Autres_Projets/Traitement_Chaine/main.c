#include <stdio.h>
#include <stdlib.h>

#include "chaines.h"

/*
 * 
 */
int main(int argc, char** argv)
{
    char uneChaine[50];
    int palindrome;
/*    int nbEspace;

    char chaine2[50];
    int taille;
    int longueur;
    
    printf("Saisir une chaine de caractère : ");
    scanf("%s", uneChaine);
    longueur = CalculerLongueur(uneChaine);
    printf("La longueur de la chaine est : %d caractère(s)\n", longueur);
    printf("Saisir une 2ème chaine de caractère : ");
    scanf("%s", chaine2);
    taille = ComparerChaine(uneChaine, chaine2);
    if (taille > 0)
    {
        printf("%s est supérieur lexicographiquement %s\n", uneChaine, chaine2);
    }
    if (taille < 0)
    {
        printf("%s est inférieur lexicographiquement %s\n", uneChaine, chaine2);
    }
    if (taille == 0)
    {
        printf("%s et %s sont identiques\n", uneChaine, chaine2);
    }
    
    printf("Entrer une chaine avec éventuellement des espaces : ");
    fgets(uneChaine, 49, stdin);
    nbEspace = SupprimerEspace(uneChaine);
    printf("le nombre d'espace est : %d \n",nbEspace);
    printf("la chaine sans espace est : %s \n",uneChaine);
  */
    printf("Entrez un palindrome : \n");
    fgets(uneChaine, 49, stdin);
    palindrome = RechercherPalindrome(uneChaine);
    if(palindrome == 1){
        printf("Ce n'est pas un palindrome\n");
    }
    else
    {
        printf("C'est un palindrome\np");
    }
    return (EXIT_SUCCESS);
}

