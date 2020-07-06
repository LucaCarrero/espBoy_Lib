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
    fileList = LinkedList<MyFile*>();
  
    return true;
}

void SdUtility::loadFileList(File dir, String path){
 while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }

    if (entry.isDirectory()) {
      String temp = String(path + entry.name());
      temp = String(temp + "/");
     loadFileList(entry,temp);
    } else {
         MyFile *temp = new MyFile();
         temp->setPath(path);
         temp->setNome(entry.name());
         fileList.add(temp);
       
    }
    entry.close();
  }
}

File SdUtility::getRoot(){
    return root;
}




//Gestione del file system dei giochi

void MyFile::setNome(String nome){
  MyFile::nomeFile = nome;
}

void MyFile::setPath(String p){
  MyFile::path = p;
}

String MyFile::getPath(){
  return MyFile::path;
}

String MyFile::getNome(){
  return MyFile::nomeFile;
}