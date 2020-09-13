#ifndef KeyController_h
#define KeyController_h

#include "Arduino.h"
#include <PCF8574.h>

class KeyController
{
private:
    int up = P7;
    int down = P0;
    int left = P3;
    int right = P5;
    int a = P1;
    int b = P2;

    void (*upCallBack)() = NULL;
    void (*downCallBack)() = NULL;
    void (*leftCallBack)() = NULL;
    void (*rightCallBack)() = NULL;
    void (*aCallBack)() = NULL;
    void (*bCallBack)() = NULL;

public:
    PCF8574 keyExt = PCF8574(0x20);

    bool begin();
    void saveKeyMap();
    void loadKeyMap();

    bool isUpPressed();
    bool isDownPressed();
    bool isLeftPressed();
    bool isRightPressed();
    bool isAPressed();
    bool isBPressed();

    void onUpPress(void (*)());
    void onDownPress(void (*)());
    void onLeftPress(void (*)());
    void onRightPress(void (*)());
    void onAPress(void (*)());
    void onBPress(void (*)());
    bool buttonEventListener();
};

#endif