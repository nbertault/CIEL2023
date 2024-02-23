/* 
 * File:   Cadran.h
 * Author: philippe
 *
 * Created on 4 janvier 2024, 08:55
 */

#include <SSD1306.h>

#ifndef CADRAN_H
#define CADRAN_H

class Cadran : public SSD1306 {
public:
    Cadran(const int16_t _dx = 20, const int16_t _dy = 16);
    void Afficher(const int _heures, const int _minutes);
    void Afficher(const String _texte, const int _valeur);

private:
    int16_t dx; 
    int16_t dy; 
};

#endif /* CADRAN_H */

