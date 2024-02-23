#include <Arduino.h>
#include <Keypad.h>
#include <string.h>

static const uint8_t LIGNES = 4;
static const uint8_t COLONNES = 3;

//clavier à l'envers
char touches[LIGNES * COLONNES] = {

    '#', '0', '*',
    '9', '8', '7',
    '6', '5', '4',
    '3', '2', '1',
};
//affectation pour un connecteur en bas
//affectation des E/S GPIO aux lignes L0,L1,L2,L3 du clavier
uint8_t brochesEnLigne[LIGNES] = {32, 33, 25, 26};
//affectation des E/S GPIO aux colonnes C0,C1,C2 du clavier
uint8_t brochesEnColonne[COLONNES] = {4, 5, 15};

Keypad clavier(touches, brochesEnLigne, brochesEnColonne, LIGNES, COLONNES);

String code;

void setup() {
    Serial.begin(115200);
    code.clear();
}

void loop() {
    
    char touche = clavier.getKey();
    if (touche != NO_KEY) {
        if (touche != '#' && touche != '*') {
            code += touche;
        }
        if (touche == '#') {
            Serial.println(code);
            code.clear();
        }
    }
}
