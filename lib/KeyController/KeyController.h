#ifndef KeyController_h
#define KeyController_h

#include "Arduino.h"
#include <PCF8574.h>

class KeyController{
    private:
        int up;
        int down;
        int left;
        int right; // puntatori a funzione?
        int a;
        int b;
    public:
        bool begin();
        bool isUpPressed(); // usarle con un puntatore a funzione come call back?  così da configurarle nel setup e una fuzione unica nel loop che controlla i pulsanti.
        bool isDownPressed();
        bool isLeftPressed();
        bool isRightPressed();
        bool isAPressed();
        bool isBPressed();
        void saveKeyMap();
};

#endif