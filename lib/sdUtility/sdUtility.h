#ifndef sdUtility_h
#define sdUtility_h

#include "Arduino.h"
#include <SPI.h>
#include <SD.h>
#include <LinkedList.h>

class myFile {
private:
    String nomeFile;
    String path;
public:
  void setNome(String nome);
 void setPath(String p);
  String getPath();
  String getNome();
};

class SdUtility {
private:
    File root;
    LinkedList<myFile*> myGame;
public:
  bool init(int cs);
  void findGame(File dir, String path) ;
  File getRoot();

};
#endif