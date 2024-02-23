/* 
 * File:   main.cpp
 * Author: nbertault
 *
 * Created on 31 janvier 2024, 08:53
 */

#include <cstdlib>
#include "plateau.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    Plateau lePlateau;
    
    bool fin = false;
    
    lePlateau.Afficher();
    
    do{
        fin = lePlateau.JouerCoup();
    }while(fin != true);
    
    lePlateau.AfficherResultat();

    return 0;
}

