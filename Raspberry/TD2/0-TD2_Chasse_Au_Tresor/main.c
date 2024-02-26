#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>

#define FAUX 0
#define VRAI 1
/*
 * 
 */
int main(int argc, char** argv)
{
    srand(time(NULL));
    int posX = 4;
    int posY = 4;
    int preX ;
    int preY ;
    int tresorX = rand() % 8;
    int tresorY = rand() % 8;
    int touche ;
    int sortie = FAUX;
    
    InitialiserLeds();
    InitialiserJoystick();
    
    do
    {
        preX = posX;
        preY = posY;
        if (posX != tresorX || posY != tresorY){
            Allumer (tresorX, tresorY, ORANGE);
            Allumer (posX, posY, ROUGE);
        }
        else{
        Allumer (tresorX, tresorY, VERT);
            sleep(1);
            tresorY = rand() % 8;
            tresorX = rand() % 8;   
        }
        while(posX == tresorX & posY == tresorY){
            tresorX = rand() % 8;
            tresorY = rand() % 8;
        }
        touche = ScannerJoystick();
        switch(touche)
        {
        case KEY_ENTER:
            sortie = VRAI;
            break;
        case KEY_RIGHT:
            posY++;
            if (posY > 7){
                posY = 7;
            }
            break;
        case KEY_LEFT:
            posY--;
            if (posY < 0){
                posY = 0;
            }
            break;
        case KEY_UP:
            posX--;
            if (posX < 0){
                posX = 0;
            }
            break;
        case KEY_DOWN:
            posX++;
            if (posX > 7){
                posX = 7;
            }
            break;
        }
        if (posX != preX || posY != preY){
            Effacer();
        }
    } while(sortie == FAUX);
    return (EXIT_SUCCESS);
}

