#include "sdUtility.h"
#include <LinkedList.h>
#include <SPI.h>
#include <SD.h>
#include <SPI.h>
#include <SD.h>


// gestionr della micro sd

bool SdUtility::init(int cs){
     if (!SD.begin(cs)) {
        return false;
    }

    root = SD.open("/");
    myGame = LinkedList<myFile*>();
  
    return true;
}

void SdUtility::findGame(File dir, String path){
 while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }

    if (entry.isDirectory()) {
      String temp = String(path + entry.name());
      temp = String(temp + "/");
      findGame(entry,temp);
      
    } else {
       if(strstr(entry.name(),".bin")){
         myFile *temp = new myFile();
         temp->setPath(path);
         temp->setNome(entry.name());

        myGame.add(temp);
       }
    }
    entry.close();
  }
}

File SdUtility::getRoot(){
    return root;
}




//Gestione del file system dei giochi

void myFile::setNome(String nome){
  myFile::nomeFile = nome;
}

void myFile::setPath(String p){
  myFile::path = p;
}

String myFile::getPath(){
  return myFile::path;
}

String myFile::getNome(){
  return myFile::nomeFile;
}