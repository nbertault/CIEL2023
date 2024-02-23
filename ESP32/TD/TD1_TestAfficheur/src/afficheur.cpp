#include "afficheur.h"

SSD1306 afficheurOLED(0x3C, 21, 22);

void InitialiserAfficheur(void) {
    afficheurOLED.init();
    afficheurOLED.flipScreenVertically();
}

void AfficherTemperature(const int _temperature, const int _dixieme) {
    afficheurOLED.clear();
    afficheurOLED.drawRect(0, 0, 127, 63);
    afficheurOLED.setFont(DejaVu_Sans_Mono_16);
    afficheurOLED.setTextAlignment(TEXT_ALIGN_RIGHT);
    afficheurOLED.drawString(120, 10, "°C");
    afficheurOLED.drawString(120, 30, "." + String(_dixieme));


    int taille = afficheurOLED.getStringWidth("°C");
    afficheurOLED.setFont(DejaVu_Sans_Mono_32);
    if (_temperature < 0) {
        afficheurOLED.drawString(130 - taille, 10, String(_temperature));
    } else {
        afficheurOLED.drawString(130 - taille, 10, "+" + String(_temperature));
    }
    afficheurOLED.display();
}

