#include <Arduino.h>
#include <SSD1306.h>
SSD1306 afficheurOLED(0x3C, 21, 22);

void setup() {
    afficheurOLED.init();
    afficheurOLED.flipScreenVertically();
    afficheurOLED.setFont(ArialMT_Plain_16);
    afficheurOLED.drawRect(0, 0, 127, 63);
    afficheurOLED.drawString(20, 5, "Hello world !");
    afficheurOLED.display();
}

void loop() {
}