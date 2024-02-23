//#include "gache.h"
//
//Gache *laGache;
//
//void setup()
//{
//    pinMode(BP1,INPUT);
//    laGache = new Gache;
//}
//
//void loop()
//{
//    if(digitalRead(BP1) == LOW)
//    {
//        Serial.println("BP1");
//        laGache->Ouvrir();
//    }
//}

#include "digicode.h"

Digicode *leDigicode;

void setup()
{
    Serial.begin(115200);
    leDigicode = new Digicode();
}

void loop()
{
    leDigicode->Controler();
}