#include <Arduino.h>
#include "sdUtility.h"
#include "Menu.h"
#include<U8g2lib.h>
 
#ifdef U8X8_HAVE_HW_SPI
#include<SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include<Wire.h>
#endif
 
 U8G2_PCD8544_84X48_1_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 13, /* cs=*/ 16, /* dc=*/ 0, /* reset=*/ 2);

SdUtility s;
Menu m;

void setup() {
  pinMode(1, OUTPUT);
  pinMode(16, OUTPUT);

  digitalWrite(16, HIGH);
  digitalWrite(1, LOW);
  if(!s.init(15)){
    return;
  }
  char * basePath = (char *)malloc(2);
  strcpy(basePath, "/"); 
  

  s.loadFileList(s.getRoot() ,basePath );
  
  Serial.begin(9600);
  char ** d = s.getFileList();
  Serial.print(d[0]);
 //return;
  digitalWrite(16, LOW);
  digitalWrite(1, HIGH);

  u8g2.begin();
  u8g2.setContrast(115);

  m.setMenuItem(d);
}

void loop() { u8g2.setFont(u8g2_font_4x6_tf);
  // put your main code here, to run repeatedly:
u8g2.firstPage();
 do {
    m.disegnaM(u8g2);
    
  } while( u8g2.nextPage() );
 
 // rebuild the picture after some delay
 delay(1000);
} 