#include <Arduino.h>
#include "sdUtility.h"
#include "Menu.h"


SdUtility s;

void setup() {
  Serial.begin(9600);
  if(!s.init(15)){
    return;
  }
  char * basePath = (char *)malloc(2);
  strcpy(basePath, "/"); 
  

  s.loadFileList(s.getRoot() ,basePath );

  Serial.println(s.getFileList()[0]);

  
}

void loop() {
  // put your main code here, to run repeatedly:
 
} 