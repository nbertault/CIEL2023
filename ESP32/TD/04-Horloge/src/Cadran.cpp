/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cadran.cpp
 * Author: nbertault
 * 
 * Created on 9 janvier 2024, 15:45
 */

#include "Cadran.h"
#include "esp32_snir.h"

Cadran::Cadran(const int16_t _dx, const int16_t _dy) :
SSD1306(ADD_OLED, SDA, SCL),
dx(_dx),
dy(_dy) {
    init();
    flipScreenVertically();
    clear();
    drawRect(0, 0, 127, 63);
    display();
}

void Cadran::Afficher(const int _heures, const int _minutes) {
    clear();
    drawRect(0, 0, 127, 63);
    setFont(ArialMT_Plain_24);
    String texte;
    if (_heures < 10)// Heures Inf. à 10
    {
        texte = "0" + String(_heures);
    } else {

        texte = String(_heures);
    }
    texte += " : ";
    if (_minutes < 10)// Minutes Inf. à 10
    {

        texte += "0" + String(_minutes);
    } else {

        texte += String(_minutes);
    }
    drawString(dx + 5, dy, texte);
    display();
}

void Cadran::Afficher(const String _chaine, const int _valeur) {
    clear();
    drawRect(0, 0, 127, 63);
    setFont(ArialMT_Plain_16);
    drawString(dx, dy, _chaine);
    int longTexte = getStringWidth(_chaine);
    setFont(ArialMT_Plain_24);
    if (_valeur < 10) {
        drawString(dx + longTexte + 5, dy, "0" + String(_valeur));
    } else {
        drawString(dx + longTexte + 5, dy, String(_valeur));
    }
    display();
}