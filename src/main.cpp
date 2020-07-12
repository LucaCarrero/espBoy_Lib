#include <Arduino.h>
#include "sdUtility.h"


SdUtility s;

void setup() {

  if(!s.init(15)){
    return;
  }
  char * basePath = (char *)malloc(2);
  strcpy(basePath, "/"); 
  

  s.loadFileList(s.getRoot() ,basePath );
 
  String temp = String(s.findFilePath("Blink.bin") ) + String("Blink.bin");

  s.loadSketchFromSD((char *)temp.c_str());
  //Serial.println(ESP.getFreeHeap());
}

void loop() {
  // put your main code here, to run repeatedly:
 
}