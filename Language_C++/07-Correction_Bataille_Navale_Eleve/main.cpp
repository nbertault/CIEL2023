/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: nbertault
 *
 * Created on 14 février 2024, 10:43
 */

#include <cstdlib>
#include "flotte.h"
#include "plateau.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Plateau lePLateau("LaFlotte.txt");
    lePLateau.Jouer();
    return 0;
}

