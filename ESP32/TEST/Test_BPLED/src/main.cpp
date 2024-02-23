#include <Arduino.h>
#include "esp32_snir.h"

void setup() {
    pinMode(BP1, INPUT);
    pinMode(BP2, INPUT);
    pinMode(BP3, INPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
}

void loop() {
    if (digitalRead(BP1) == LOW)
        digitalWrite(LED1, HIGH);
    if (digitalRead(BP2) == LOW)
        digitalWrite(LED2, HIGH);
    if (digitalRead(BP3) == LOW) {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
    }
}