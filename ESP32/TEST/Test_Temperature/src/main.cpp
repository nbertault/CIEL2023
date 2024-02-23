#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "esp32_snir.h"
OneWire onWire(ONE_WIRE_BUS);
DallasTemperature capteurTemp(&onWire);

void setup() {
    Serial.begin(115200);
    capteurTemp.begin();
    uint8_t nbCapteurs = capteurTemp.getDS18Count();
    Serial.printf("Nombre de capteurs sur le bus %d\n\r", nbCapteurs);
}

void loop() {
    capteurTemp.requestTemperatures();
    float temperature = capteurTemp.getTempCByIndex(0);
    Serial.print("La température est de : ");
    Serial.print(temperature);
    Serial.println("° Celsius");
    delay(1000);
}