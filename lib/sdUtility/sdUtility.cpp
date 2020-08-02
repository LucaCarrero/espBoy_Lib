#include "sdUtility.h"
#include <LinkedList.h>
#include <SPI.h>
#include <SD.h>

// gestionr della micro sd

bool SdUtility::init(int cs)
{
  if (!SD.begin(cs))
  {
    return false;
  }

  root = SD.open("/");
  fileList = LinkedList<MyFile *>();
  
  return true;
}

void SdUtility::loadFileList(File dir, String path)
{
  while (true)
  {

    File entry = dir.openNextFile();
    if (!entry)
    {
      // no more files
      break;
    }

    if (entry.isDirectory())
    {
      String temp = String(path + entry.name());
      temp = String(temp + "/");
      loadFileList(entry, temp);
    }
    else
    {
      char *ext = getFileExt(entry.name());
      if (strstr(ext, ".bin") || strstr(ext, ".sav"))
      {
        MyFile *temp = new MyFile();
        temp->setPath(path);
        temp->setNome(entry.name());

        fileList.add(temp);
      }
    }
    entry.close();
  }
}

File SdUtility::getRoot()
{
  return root;
}

int SdUtility::fileNumber()
{
  return fileList.size();
}

char *SdUtility::getFileExt(const char *string)
{
  assert(string != NULL);
  char *ext = strrchr(string, '.');

  if (ext == NULL)
    return (char *)string + strlen(string);

  for (char *iter = ext + 1; *iter != '\0'; iter++)
  {
    if (!isalnum((unsigned char)*iter))
      return (char *)string + strlen(string);
  }

  return ext;
}

String SdUtility::findFilePath(char *fileName)
{
  for (int i = 0; i < fileList.size(); i++)
  {
    MyFile cur = *(fileList.get(i));
    String temp = cur.getNome();

    if (strcmp(fileName, temp.c_str()) == 0)
    {
      return cur.getPath();
    }
  }
  return String("");
}

bool SdUtility::loadSketchFromSD(char *fileName)
{
  uint32_t maxSketchSpace = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
  if (Update.begin(maxSketchSpace, U_FLASH)){ 

    File myDataFile = SD.open(fileName, FILE_READ);

    while (myDataFile.available())
    {
      uint8_t ibuffer[128];
      myDataFile.read((uint8_t *)ibuffer, 128);
      Update.write(ibuffer, sizeof(ibuffer));
    }
    myDataFile.close();
    Update.end(true);
    ESP.restart();
  }
}

char **  SdUtility::getFileList(){
  int numberOfFile = fileList.size();
  char ** file = (char **)malloc(numberOfFile * sizeof(char *));

  for(int i = 0; i < numberOfFile; i++){
      MyFile *temp = fileList.get(i);

      const char * path = temp->getPath();
      const char * nameFile =  temp->getNome();
      int strL = strlen(path) + strlen(nameFile) +1;
      file[i] = (char *)malloc(strL * sizeof(char ));
      strcpy(file[i] , path  );
      strcat(file[i],nameFile);
  }
  return file;
}

int SdUtility::getNumOfFile(){
  return  fileList.size();
}
//Gestione del file system dei giochi

void MyFile::setNome(String nome)
{
  char *temp = (char *)malloc(nome.length() * sizeof(char));
  strcpy(temp, nome.c_str());

  MyFile::nomeFile = temp;
}

void MyFile::setPath(String p)
{
  char *temp = (char *)malloc(p.length() * sizeof(char));
  strcpy(temp, p.c_str());

  MyFile::path = temp;
}

char * MyFile::getPath()
{

  return (char *)MyFile::path;
}

char * MyFile::getNome()
{
  return (char *)MyFile::nomeFile;
}