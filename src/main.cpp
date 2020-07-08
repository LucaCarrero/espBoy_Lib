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
  
    
  s.loadFileList(s.getRoot() ,basePath );
   
  Serial.print(s.fileNumber());
   Serial.println(s.findFilePath("Blink.bin"));
}

void loop() {
  // put your main code here, to run repeatedly:
}