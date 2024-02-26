/* 
 * File:   Serrure.h
 * Author: nbertault
 *
 * Created on 23 janvier 2024, 15:55
 */

#ifndef SERRURE_H
#define SERRURE_H
#include "esp32_snir.h"
#include <ESP32Servo.h>
#include <Adafruit_NeoPixel.h>
#include <Arduino.h>

class Serrure : public Servo{
public:
    Serrure(const uint8_t _broche = PWM);
    ~Serrure();
    void Deverouiller();
    void Verrouiller();
private:
    Adafruit_NeoPixel *ledRGB;
uint8_t broche;
};

#endif /* SERRURE_H */

