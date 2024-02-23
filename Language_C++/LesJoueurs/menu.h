/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   menu.h
 * Author: nbertault
 *
 * Created on 30 janvier 2024, 15:32
 */

#ifndef MENU_H
#define MENU_H
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

enum CHOIX_MENU
{
    AJOUTER = 1,
    VISUALISER,
    CHARGER,
    SAUVEGARDER,
    QUITTER
};

class Menu
{
public:

    Menu(const string &_nom);
    ~Menu();
    int AfficherEtAttendreChoix();
    static void EffacerEcran();
    static void AttendreAppuiTouche();
private:
    string nom;
    string* options;
    int nbOptions;
    int longueurMax;
};

#endif /* MENU_H */

