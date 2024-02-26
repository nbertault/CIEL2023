/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: pcruchet
 *
 * Created on 10 décembre 2018, 13:15
 */

#include "include/led-matrix-c.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>

void AfficherLabyrinthe(int _image[][32], int _height, int _width, struct LedCanvas *_canvas)
{


    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width / 2; ++x)
        {
            if (y == 0 || x == 0 || y == 31 || x == 31)
            {//Murs extérieur
                led_canvas_set_pixel(_canvas, x, y, 0x02, 0xaa, 0x10);
            }
            if (_image[y][x] == 1)
            {//Murs intérieurs
                led_canvas_set_pixel(_canvas, x, y, 0x6f, 0x6f, 0);
            }
            if (_image[y][x] == 2)
            {//Énemies
                led_canvas_set_pixel(_canvas, x, y, 0x6f, 0, 0);
            }
            if (_image[y][x] == 3)
            {//Arrivées
                led_canvas_set_pixel(_canvas, x, y, 0, 0x6f, 0);
            }
        }
    }

}

void DefinirLimites(int _image[][32], int _height, int _width, struct LedCanvas *_canvas, int *_posY, int _preY, int *_posX, int _preX, int *_fin, struct RGBLedMatrix *_matrix)
{
    
    if (_image[*_posY][*_posX] == 1)
    {//Empêche de passer à travers les murs
        *_posY = _preY;
        *_posX = _preX;
    }


    if (_image[*_posY][*_posX] == 2)
    {//Quand touche énemie recommence
        *_posY = 1;
        *_posX = 1;
    }

    if (_image[*_posY][*_posX] == 3)
    {//Quand arrive gagne
        *_fin = 1;
        printf("sortie\n");
    }

    if (*_posY != _preY || *_posX != _preX)
    {
        led_canvas_set_pixel(_canvas, _preX, _preY, 0, 0, 0); //Effacer ancien personnage
    }

    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width / 2; ++x)
        {
            if (_image[y][x] == 3)
            {//Arrivées
                led_canvas_set_pixel(_canvas, x, y, 0, 0x6f, 0);
            }
        }
    }
    led_canvas_set_pixel(_canvas, *_posX, *_posY, 0, 0, 0x6f); //Personnage
}

void setNonBlockingMode(int shouldBlock)
{
    struct termios ttystate;

    // Récupération des paramètres du terminal
    tcgetattr(STDIN_FILENO, &ttystate);

    if (shouldBlock)
    {
        // Activation du mode non bloquant
        ttystate.c_lflag |= ICANON;
    }
    else
    {
        // Désactivation du mode non bloquant
        ttystate.c_lflag &= ~ICANON;
    }

    // Application des changements aux paramètres du terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    struct RGBLedMatrixOptions options;
    struct RGBLedMatrix *matrix;
    struct LedCanvas *offscreen_canvas;
    int width, height;
    int x, y, i;
    int posX = 1;
    int posY = 1;
    int preX;
    int preY;
    int fin = 0;

    struct LedFont *font = load_font("fonts/4x6.bdf"); //définition de la font

    memset(&options, 0, sizeof (options));
    options.rows = 32;
    options.chain_length = 2;

    matrix = led_matrix_create_from_options(&options, &argc, &argv);
    if (matrix == NULL)
    {
        perror("Erreur à la création de la matrice de Led ");
        exit(1);
    }

    offscreen_canvas = led_matrix_create_offscreen_canvas(matrix);

    led_canvas_get_size(offscreen_canvas, &width, &height);

    int image1[32][32] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 2, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 2, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 2, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int image2[32][32] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 2, 1, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 2, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 2, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 2, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 2, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 2, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 2, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 2, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 1, 0, 2, 0, 1, 2, 1, 0, 0, 1, 1, 1, 1, 2, 0, 1, 0, 1, 0, 2, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    int image3[32][32] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 0, 1, 0, 2, 0, 0, 1, 1, 0, 1, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 2, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 2, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 3, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 2, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 2, 0, 1, 0, 1, 0, 1, 0, 2, 0, 1, 0, 1, 1, 1, 0, 1, 2, 1, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    int numLab = rand() % 3;


    led_canvas_set_pixel(offscreen_canvas, posX, posY, 0, 0, 0x6f); //Personnage

    led_canvas_clear(matrix); //Éteindre toutes les Leds
    switch (numLab)
    {
    case 0:
        AfficherLabyrinthe(image1, height, width, offscreen_canvas);
        break;
    case 1:
        AfficherLabyrinthe(image2, height, width, offscreen_canvas);
        break;
    case 2:
        AfficherLabyrinthe(image3, height, width, offscreen_canvas);
        break;
    }

    offscreen_canvas = led_matrix_swap_on_vsync(matrix, offscreen_canvas); //Afficher toutes les leds
    sleep(5);

    led_canvas_clear(matrix); //Éteindre toutes les Leds
    led_canvas_set_pixel(offscreen_canvas, posX, posY, 0, 0, 0x6f); //Personnage

    offscreen_canvas = led_matrix_swap_on_vsync(matrix, offscreen_canvas); //Afficher toutes les leds


    setNonBlockingMode(0);
    char touche;
    int sortie = 0;
    do
    {

        printf("posx : %d\n", posX);

        if (read(STDIN_FILENO, &touche, 1) == 1)
        {
            preX = posX;
            preY = posY;
            switch (touche)
            {
            case 'z':
                posY--;
                if (posY < 1)
                {
                    posY = 1;
                }

                break;

            case 'q':
                posX--;
                if (posX < 1)
                {
                    posX = 1;
                }
                break;

            case 's':
                posY++;
                if (posY > 30)
                {
                    posY = 30;
                }
                break;

            case 'd':
                posX++;
                if (posX > 30)
                {
                    posX = 30;
                }
                break;
            }
        }
        led_canvas_clear(matrix); //Éteindre toutes les Leds
        switch (numLab)
        {
        case 0:
            DefinirLimites(image1, height, width, offscreen_canvas, &posY, preY, &posX, preX, &fin, matrix);
            break;
        case 1:
            DefinirLimites(image2, height, width, offscreen_canvas, &posY, preY, &posX, preX, &fin, matrix);
            break;
        case 2:
            DefinirLimites(image3, height, width, offscreen_canvas, &posY, preY, &posX, preX, &fin, matrix);
            break;
        }


        offscreen_canvas = led_matrix_swap_on_vsync(matrix, offscreen_canvas); //Afficher toutes les leds
        usleep(50000);

    }
    while (fin != 1);
    setNonBlockingMode(1);

    //Fin
    led_canvas_clear(matrix); //Éteindre toutes les Leds

    for (i = 1; i <= 12; i++)//animation de fin
    {
        draw_circle(offscreen_canvas, 32, 15, i, 0xff, 00, 00);
        draw_circle(offscreen_canvas, 32, 15, i - 6, 0, 00, 00);

        usleep(250000);
        offscreen_canvas = led_matrix_swap_on_vsync(matrix, offscreen_canvas);

    }

    usleep(250000);
    struct LedFont *fon = load_font("fonts/6x10.bdf"); //définition de la font
    led_canvas_clear(offscreen_canvas); //Éteindre toutes les Leds
    draw_circle(offscreen_canvas, 32, 15, 8, 0xff, 00, 00);
    draw_circle(offscreen_canvas, 32, 15, 10, 0xff, 00, 00);
    draw_circle(offscreen_canvas, 32, 15, 12, 0xff, 00, 00);
    draw_text(offscreen_canvas, fon, 27, 19, 0xff, 0xFF, 0, "12", 1);
    offscreen_canvas = led_matrix_swap_on_vsync(matrix, offscreen_canvas);
    sleep(100);

    return (EXIT_SUCCESS);
}