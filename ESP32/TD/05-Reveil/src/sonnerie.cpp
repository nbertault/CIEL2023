/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Sonnerie.cpp
 * Author: nbertault
 * 
 * Created on 23 janvier 2024, 08:30
 */

#include "sonnerie.h"

Sonnerie::Sonnerie(const uint8_t _broche) :
broche(_broche)
{
    pinMode(broche,OUTPUT);
    digitalWrite(broche,LOW);
}

void Sonnerie::Declencher()
{
    digitalWrite(broche,HIGH);
}


void Sonnerie::Arreter()
{
    digitalWrite(broche,LOW);
}