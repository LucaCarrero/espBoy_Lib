#include <Arduino.h>
#include "BootLoader.h"
#include "KeyController.h"

#define USE_KEY_CIP 1
KeyController k;

void prova()
{
    Serial.print("ciao");
}

void setup()
{

    Serial.begin(9600);
    k.begin();
    k.onDownPress(prova);
    //boot (1);
}

void loop()
{
    k.buttonEventListener();
}