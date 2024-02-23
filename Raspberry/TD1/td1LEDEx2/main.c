#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>
/*
 * 
 */

/* -------Première Ligne-------

int main(int argc, char** argv)
{
    int colonne;
    InitialiserLeds();
    
    for(colonne = 0; colonne <=7; colonne++)
    {
        Allumer(0,colonne,ROUGE);
    }
    Effacer();
    
    return (EXIT_SUCCESS);
}

*/

/*  -----------Première colonne-----------

int main(int argc, char** argv)
{
    int colonne;
    InitialiserLeds();
    
    for(colonne = 0; colonne <=7; colonne++)
    {
        Allumer(colonne,0,ROUGE);
    }
    Effacer();
    
    return (EXIT_SUCCESS);
}
*/


/* -------1 sur 2 première colonne---------

int main(int argc, char** argv)
{
    int colonne;
    InitialiserLeds();
    
    for(colonne = 0; colonne <=7; colonne+=2)
    {
        Allumer(colonne,0,ROUGE);
    }
    Effacer();
    
    return (EXIT_SUCCESS);
}
*/



/* --------4 leds rouges---------

int main(int argc, char** argv)
{
    int colonne;
    InitialiserLeds();
    
    for(colonne = 2; colonne <=5; colonne++)
    {
        Allumer(colonne,0,ROUGE);
    }
    Effacer();
    
    return (EXIT_SUCCESS);
}
*/
