#ifndef Bootloader_h
#define BootLoader_h

#include "Arduino.h"
#include "sdUtility.h"
#include <SPI.h>
#include <SD.h>
#include "ArduinoJson.h"

class Boot{
    public:
        Boot(int cs);
};

Boot::Boot(int cs = 1){
  
    if(!SD.begin(cs)){
        return;
    }

    File config = SD.open("config.conf", FILE_READ);
    File boot = SD.open("boot.bin", FILE_READ);

    if(! (config.available()) ){
        return;
    }

    String configContent = String("");

    while (config.available())
    {
      configContent = configContent + (char)config.read();
    } 
    config.close();
   
   StaticJsonDocument<200> doc;
    DeserializationError err = deserializeJson(doc, configContent.c_str());
    config = SD.open("config.conf", "w");

    if(doc["gameLoaded"] == 1){
        doc["gameLoaded"] = 0;
        
        config.println(doc.as<String>());

        return;
    }else{
        doc["gameLoaded"] = 1;
 
        config.println(doc.as<String>());

        SdUtility s;
        s.loadSketchFromSD("/boot.bin");

        return;
    }
    config.close();
    
}
#endif