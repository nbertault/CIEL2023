#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int val1 = 6;
    int val2 = 2;
    char operateur;
    printf("Choisissez une opération parmi : +, - ,* ,/ : ");
    operateur = getchar();
    switch (operateur)
    {
        case '+': printf("\n%d + %d = %d\n",val1,val2,val1+val2);
        break;
        case '-': printf("\n%d - %d = %d\n",val1,val2,val1-val2);
        break;
        case '*': printf("\n%d * %d = %d\n",val1,val2,val1*val2);
        break;
        case '/': printf("\n%d / %d = %d\n",val1,val2,val1/val2);
        break;
        default: printf("\nJe ne connais pas cette opération\n");
    }
    return (EXIT_SUCCESS);
}

