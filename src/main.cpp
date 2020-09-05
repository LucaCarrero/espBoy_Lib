#include <Arduino.h>
#include "BootLoader.h"
#include "KeyController.h"

void p (int i){
    Serial.begin(9600);
    Serial.print(i);
}

void setup() {
    KeyController k;
    k.setF(p);
    k.prova(2);
 //boot (1);
}

void loop() {
} 