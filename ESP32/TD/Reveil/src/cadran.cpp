/* 
 * File:   Cadran.cpp
 * Author: philippe
 * 
 * Created on 4 janvier 2024, 08:55
 */

#include "cadran.h"
#include "esp32_snir.h"

Cadran::Cadran(const int16_t _dx, const int16_t _dy) :
SSD1306(ADD_OLED, SDA, SCL),
dx(_dx),
dy(_dy)
{
    init();
    flipScreenVertically();
    clear();
    drawRect(0, 0, 128, 64);
    display();
}

/**
 * @brief Cadran::Afficher
 * @details : Affiche les heures et le minutes séparées par ':'
 * @param _heures   valeurs des heures
 * @param _minutes  valeurs des minutes
 */
void Cadran::Afficher(const int _heures, const int _minutes)
{
    String heuresMinutes;
    
    if (_heures < 10)
        heuresMinutes += '0';
    heuresMinutes += _heures;
    heuresMinutes += " : ";
     if (_minutes < 10)
        heuresMinutes += '0';
    heuresMinutes += _minutes;
    
    clear();
    drawRect(0, 0, 128, 64);
    setFont(ArialMT_Plain_24);
    drawString(dx + 5, dy, heuresMinutes);
    display();
}

/**
 * @brief Cadran::Afficher
 * @details : Affiche un texte en police 16 et une valeur en police 32
 * @param _texte    Le texte indiquant la fonction
 * @param _valeur   La valeur à afficher
 */
void Cadran::Afficher(const String _texte, const int _valeur)
{
    clear();
    drawRect(0, 0, 128, 64);
    setFont(ArialMT_Plain_16);
    String s1 = _texte + "   ";
    drawString(dx, dy, s1);
    int pos = getStringWidth(s1);
    s1.clear();
    if (_valeur < 10)
        s1 = "0";
    s1 += _valeur;
    setFont(ArialMT_Plain_24);
    drawString(dx + pos, dy, s1);
    display();
}

void Cadran::Afficher(const String _texte, const String _valeur)
{
    clear();
    drawRect(0, 0, 128, 64);
    setFont(ArialMT_Plain_16);
    String s1 = _texte + "   ";
    drawString(dx, dy, s1);
    int pos = getStringWidth(s1);
    setFont(ArialMT_Plain_24);
    drawString(dx + pos, dy, _valeur);
    display();
}