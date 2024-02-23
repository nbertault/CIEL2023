/* 
 * File:   Clavier.h
 * Author: philippe
 *
 * Created on 3 janvier 2024, 15:12
 */

#ifndef CLAVIER_H
#define CLAVIER_H

#include <Arduino.h>

class Clavier {

public:   
   enum TOUCHES_CLAVIER 
   {
        AUCUNE = -1,
        MODE,
        PLUS,
        MOINS,
    };
    
    Clavier(const uint8_t _lesBoutonsPoussoirs[], const int _nbPoussoirs=3);
    ~Clavier();
    TOUCHES_CLAVIER Scruter();  
   
private:
    uint8_t *lesBoutonsPoussoirs;
    int nbPoussoirs;
};  

#endif /* CLAVIER_H */

#define TOTO