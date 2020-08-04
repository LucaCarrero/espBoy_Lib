#include <Arduino.h>
#include "sdUtility.h"
#include "Menu.h"
#include<U8g2lib.h>
#include <PCF8574.h>

#ifdef U8X8_HAVE_HW_SPI
#include<SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include<Wire.h>
#endif
 
 U8G2_PCD8544_84X48_1_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 13, /* cs=*/ 16, /* dc=*/ 0, /* reset=*/ 2);

SdUtility s;
Menu m;
PCF8574 pcf8574(0x20); 

void setup() {
  pcf8574.pinMode(P0, INPUT_PULLUP); // giù
  pcf8574.pinMode(P7,  INPUT_PULLUP); // su
  pinMode(1, OUTPUT);
  pinMode(16, OUTPUT);
  // don't talk to LCD while we init the SD
  digitalWrite(16, HIGH);
  digitalWrite(1, LOW);
  if(!s.init(1)){
    return;
  }
  char * basePath = (char *)malloc(2);
  strcpy(basePath, "/"); 
  

  s.loadFileList(s.getRoot() ,basePath );
  
  char ** d = s.getFileList();


 //return;

  // don't talk to SD while we init the LCD
  digitalWrite(16, LOW);
  digitalWrite(1, HIGH);

  u8g2.begin();
  pcf8574.begin();

  u8g2.setContrast(115);

  m.setMenuItem(d,s.getNumOfFile()-1
);
}

void loop() { u8g2.setFont(u8g2_font_4x6_tf);
  // put your main code here, to run repeatedly:
u8g2.firstPage();
 do {
    m.disegnaM(u8g2);
    
  } while( u8g2.nextPage() );
  m.scrolSelectedVoice(1);
 // rebuild the picture after some delay
 
  if(pcf8574.digitalRead(P0) == LOW){ // giù
    m.incIndide();
  }
  if (pcf8574.digitalRead(P7) == LOW) { // su
    m.decIndice();
  }
 delay(400);
} 