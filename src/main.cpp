#include <Arduino.h>
#include "sdUtility.h"

SdUtility s;

void setup() {
  Serial.begin(9600);

  if(!s.init(15)){
    Serial.println("error");
    return;
  }
  char * basePath = (char *)malloc(2);
  strcpy(basePath, "/"); 
  s.findGame(s.getRoot() ,basePath );
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
}