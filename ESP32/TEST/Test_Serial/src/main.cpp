#include <Arduino.h>

void setup() 
{
    Serial.begin(115200);
    Serial.println("Esp32 Initialiser");
}

void loop() 
{
    char carLu;
    if (Serial.available() > 0) 
    {
        carLu = Serial.read();
        Serial.println(carLu);
    }
}