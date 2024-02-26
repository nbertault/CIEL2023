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
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;
enum CHOIX_MENU {
        OPTION_1 = 1,
        OPTION_2,
        OPTION_3,
        OPTION_4,
        QUITTER
    };
    
class Menu {
public:

    Menu(const string &_nom);
    ~Menu();
    int Afficher();
    static void AttendreAppuiTouche();
private:
    string nom;
    string* options;
    int nbOptions;
    int longueurMax;
};

#endif /* MENU_H */

