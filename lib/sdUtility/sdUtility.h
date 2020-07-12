#ifndef sdUtility_h
#define sdUtility_h

  #include "Arduino.h"
  #include <SPI.h>
  #include <SD.h>
  #include <LinkedList.h>

  class MyFile {
  private:
    const char* nomeFile;
    const char* path;
  public:
    void setNome(String nome);
    void setPath(String p);
    String getPath();
    String getNome();

  };

  class SdUtility {
  private:
    File root;
    LinkedList<MyFile*> fileList;
  public:
    bool init(int cs);
    void loadFileList(File dir, String path);
    File getRoot(); 
    int fileNumber();
    char* getFileExt(const char *string);
    String findFilePath(char * fileName);
    bool loadSketchFromSD(char * fileName);
  };
  
#endif