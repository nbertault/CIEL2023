/* 
 * File:   Serrure.cpp
 * Author: nbertault
 * 
 * Created on 23 janvier 2024, 15:55
 */

#include "serrure.h"

Serrure::Serrure(const uint8_t _broche) :
broche(_broche) {
    int canal = attach(_broche, 800, 2000);
    ESP32PWM::allocateTimer(canal);
    ledRGB = new Adafruit_NeoPixel(1, DATALEDS, NEO_RGB);
    ledRGB->begin();
    ledRGB->clear();
    ledRGB->show();
}

Serrure::~Serrure()
{
    detach();
    delete ledRGB;
}

void Serrure::Deverouiller()
{
    write(0);
    ledRGB->setPixelColor(0,0,16,0);
    ledRGB->show();
}

void Serrure::Verrouiller()
{
    write(180);
    ledRGB->setPixelColor(0,16,0,0);
    ledRGB->show();
}