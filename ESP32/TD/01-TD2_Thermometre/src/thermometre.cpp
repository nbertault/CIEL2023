#include <Arduino.h>
#include "thermometre.h"
#include "afficheur.h"
#include <math.h>

OneWire onWire(ONE_WIRE_BUS);
DallasTemperature capteurTemp(&onWire);

void InitialiserCapteurTemperature(void) {
    Serial.begin(115200);
    capteurTemp.begin();
}

bool ObtenirTemperature(int *_temperature, int * _dixiemes, const int _numCapteur) {
    bool retour = false;
    capteurTemp.requestTemperatures();
    float temperature = capteurTemp.getTempCByIndex(_numCapteur);
    float dixiemes = ceil((temperature-trunc(temperature))*10);
    if (temperature != DEVICE_DISCONNECTED_C) {
        retour = true;
        *_dixiemes = ceil((temperature-trunc(temperature))*10);// partie décimale arondie au dixième supérieure
        *_temperature = trunc(temperature);// partie entière de la température
        Serial.print("Température: ");
        Serial.print(temperature);
        Serial.print("\n\r");
        Serial.print("Dixièmes: ");
        Serial.print(dixiemes);
        Serial.print("\n\r");
    }
    return retour;
}