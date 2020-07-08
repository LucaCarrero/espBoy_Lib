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
      char * ext = getFileEext(entry.name());
      if(strstr(ext, ".bin")  ){
         MyFile *temp = new MyFile();
         temp->setPath(path);
         temp->setNome(entry.name());
         fileList.add(temp);
       }
    }
    entry.close();
  }
  
}

File SdUtility::getRoot(){
    return root;
}

int SdUtility::fileNumber(){
  return fileList.size();
}

char* SdUtility::getFileEext(const char *string)
{
    assert(string != NULL);
    char *ext = strrchr(string, '.');
 
    if (ext == NULL)
        return (char*) string + strlen(string);
 
    for (char *iter = ext + 1; *iter != '\0'; iter++) {
        if (!isalnum((unsigned char)*iter))
            return (char*) string + strlen(string);
    }
 
    return ext;
} 

 String SdUtility::findFilePath(char * fileName){
   for(int i = 0; i< fileList.size();i++){
      MyFile cur = *(fileList.get(i));
      String temp = cur.getNome();

      if(strcmp(fileName, temp.c_str()) == 0){
        return cur.getPath();
      }
   }
   return String("");
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