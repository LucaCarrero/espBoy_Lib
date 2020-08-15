#ifndef Menu_h
#define Menu_h

#include "Arduino.h"

#include <U8g2lib.h>
#define PAGE_ELEMENT 3
class Menu {
private:
    char **s;
    int voiceNumber;
    char *titolo;
    uint8_t indice;
    int posizionScrolSelected = 0;
    int page = 0;
public:
    void disegnaM(U8G2 &t);
    Menu();
    void incIndide();
    void decIndice();
    int getInd();
    void setMenuItem(char **item,int numberOfVoice );
    void scrolSelectedVoice(uint8_t unit );
    char * getSelectedVoice();
    void setTitle(char * title);
};
#endif