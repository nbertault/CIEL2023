/* 
 * File:   Ecran.cpp
 * Author: nbertault
 * 
 * Created on 23 janvier 2024, 15:07
 */

#include "ecran.h"
#include "esp32_snir.h"

Ecran::Ecran() :
SSD1306(ADD_OLED, SDA, SCL) {
    init();
    flipScreenVertically();
    clear();
    display();
    setFont(ArialMT_Plain_16);
}

void Ecran::AfficherMessage(const String _message, const int _ligne) {

    if (_ligne == 0) {
        setColor(BLACK);
        fillRect(0, 0, 127, 31);
        setColor(WHITE);
        int pos = getStringWidth(_message);
        drawString((128 - pos) / 2, 8, _message);
        display();
    } else {
        setColor(BLACK);
        drawRect(0, 32, 127, 63);
        setColor(WHITE);
        int pos = getStringWidth(_message);
        drawString((128 - pos) / 2, 40, _message);
        display();
    }
}