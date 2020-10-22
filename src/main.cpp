#include <Arduino.h>
#include "BootLoader.h" 
#define USE_KEY_CIP 1
#include "KeyController.h"
#include "GameObject.h"

//KeyController k;

void prova()
{
    Serial.print("ciao");
}

class main : GameObject
{
private:
  
public:
void c(){
    getX();
}
};


void setup()
{

    //Serial.begin(9600);
    //k.begin();
    //k.onDownPress(prova);
   // k.saveKeyMap();
   // k.loadKeyMap();
    boot (1);
}

void loop()
{
   // k.buttonEventListener();
}