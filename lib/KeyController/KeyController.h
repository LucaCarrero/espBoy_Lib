#ifndef KeyController_h
#define KeyController_h

#include "Arduino.h"
#include <PCF8574.h>

class KeyController{
    private:
        int up;
        int down;
        int left;
        int right;
        int a;
        int b;
    public:
        bool loadKeyMap();
        bool isUpPressed();
        bool isDownPressed();
        bool idLeftPressed();
        bool isRightPressed();
        bool isAPressed();
        bool isBPressed();
        void saveKeyMap();
};

#endif