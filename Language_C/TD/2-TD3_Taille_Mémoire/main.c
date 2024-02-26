#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv)
{
    char hchar = 0x7f;
    short hshort = 0x7fff;
    long hlong = 0x7fffffffffffffff;
    int hint = 0x7fffffff;
    float hfloat = 0x7fff;
    double hdouble = 0x7fffffffffffffff;
    printf("+---------------+-------------- ---+----------------------+----------------------+\n");
    printf("|Type           | Taille en octets | Valeur la plus basse | Valeur la plus haute |\n");
    printf("+---------------+------------------+----------------------+----------------------+\n");
    printf("|char           | %16d | %20d | %20d |\n", sizeof ( char), ~hchar, hchar);
    printf("+---------------+------------------+----------------------+----------------------+\n");
    printf("|short          | %16d | %20d | %20d |\n", sizeof ( short), ~hshort, hshort);
    printf("+---------------+------------------+----------------------+----------------------+\n");
    printf("|long           | %16d | %20ld | %20ld |\n", sizeof ( long), ~hlong, hlong);
    printf("+---------------+------------------+----------------------+----------------------+\n");
    printf("|int            | %16d | %20d | %20d |\n", sizeof ( int), ~hint, hint);
    printf("+---------------+------------------+----------------------+----------------------+\n");
    printf("|unsigned char  | %16d | %20d | %20d |\n", sizeof ( unsigned char), ~hchar, hchar);
    printf("+---------------+------------------+----------------------+----------------------+\n");
    printf("|unsigned short | %16d | %20d | %20d |\n", sizeof ( unsigned short), ~hshort, hshort);
    printf("+---------------+------------------+----------------------+----------------------+\n");
    printf("|unsigned long  | %16d | %20ld | %20ld |\n", sizeof ( unsigned long), ~hlong, hlong);
    printf("+---------------+------------------+----------------------+----------------------+\n");
    printf("|unsigned int   | %16d | %20d | %20d |\n", sizeof ( unsigned int), ~hint, hint);
    printf("+---------------+------------------+----------------------+----------------------+\n");
    printf("|unsigned int   | %16d |\n", sizeof ( float));
    printf("+---------------+------------------+\n");
    printf("|float          | %16d |\n", sizeof ( double ));
    printf("+---------------+------------------+\n");
    return (EXIT_SUCCESS);
}

