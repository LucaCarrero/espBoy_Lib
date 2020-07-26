#ifndef Menu_h
#define Menu_h

#include "Arduino.h"

#include <U8g2lib.h>
#define DISPLAY_HAIGHT 84

class Menu {
private:
    char **s;
    char *titolo[10] = {"Snake"};
    int indice;
public:
    void disegnaM(U8G2 &t);
    Menu();
    void incIndide();
    void decIndice();
    int getInd();
};
#endif