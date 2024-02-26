#include "thermostat.h"

void InitialiserThermostat(void) {
    pinMode(BP1, INPUT); //Initialiser Bouton 1
    pinMode(BP2, INPUT); //Initialiser Bouton 2

    pinMode(SW, INPUT); //Initialiser Switch

    pinMode(LED1, OUTPUT); //Initialiser LED 1
    pinMode(LED2, OUTPUT); //Initialiser LED 2

    digitalWrite(LED1, LOW); //Éteindre LED 2
    digitalWrite(LED2, LOW); //Éteindre LED 2
    
    

}

float FixerConsigne(float _temp) {
    float _consigne = _temp;
        if (digitalRead(BP1) == LOW) {
            _consigne += 0.5;
        }

        if (digitalRead(BP2) == LOW) {
            _consigne -= 0.5;
        }
    
        AfficherTemperature((int)_consigne, round((_consigne - floor(_consigne))*10));
        delay(200);

    return (_consigne);
}

bool RegulerTemperature(const float _consigne,const float _temp,const int _hysteresis){
    bool marche = false;
    if(_temp >= _consigne + (_hysteresis / 2)){
        digitalWrite(LED2, HIGH);
        digitalWrite(LED1, LOW);
        marche = true;
    }
    if(_temp <= _consigne - (_hysteresis / 2)){
        digitalWrite(LED2, LOW);
        digitalWrite(LED1, HIGH);
    }
    return(marche);
}