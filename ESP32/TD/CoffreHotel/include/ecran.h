/* 
 * File:   Ecran.h
 * Author: nbertault
 *
 * Created on 23 janvier 2024, 15:07
 */

#ifndef ECRAN_H
#define ECRAN_H
#include <SSD1306.h>

class Ecran : public SSD1306{
public:
    Ecran();
    void AfficherMessage(const String _message, const int _ligne = 0);
private:

};

#endif /* ECRAN_H */

