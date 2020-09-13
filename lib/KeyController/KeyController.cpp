#include "PCF8574.h"
#include "KeyController.h"

bool KeyController::begin()
{
    bool initRis = keyExt.begin();
    keyExt.pinMode(P0, INPUT_PULLUP); // giù
    keyExt.pinMode(P7, INPUT_PULLUP); // su
    keyExt.pinMode(P1, INPUT_PULLUP); //A
    keyExt.pinMode(P2, INPUT_PULLUP); // B
    keyExt.pinMode(P5, INPUT_PULLUP); // dx
    keyExt.pinMode(P3, INPUT_PULLUP); // sx
    Serial.print(upCallBack == NULL);
}

void KeyController::saveKeyMap() {}
void KeyController::loadKeyMap() {}

bool KeyController::isUpPressed()
{
    if (keyExt.digitalRead(P7) == LOW)
    { // giù
        return true;
    }
    return false;
}
bool KeyController::isDownPressed()
{
    if (keyExt.digitalRead(P0) == LOW)
    { // giù
        return true;
    }
    return false;
}
bool KeyController::isLeftPressed()
{
    if (keyExt.digitalRead(P3) == LOW)
    { // giù
        return true;
    }
    return false;
}
bool KeyController::isRightPressed()
{
    if (keyExt.digitalRead(P5) == LOW)
    { // giù
        return true;
    }
    return false;
}
bool KeyController::isAPressed()
{
    if (keyExt.digitalRead(P1) == LOW)
    { // giù
        return true;
    }
    return false;
}
bool KeyController::isBPressed()
{
    if (keyExt.digitalRead(P2) == LOW)
    { // giù
        return true;
    }
    return false;
}

void KeyController::onUpPress(void (*up)())
{
    upCallBack = up;
}
void KeyController::onDownPress(void (*down)())
{
    downCallBack = down;
}
void KeyController::onLeftPress(void (*left)())
{
    leftCallBack = left;
}
void KeyController::onRightPress(void (*right)())
{
    rightCallBack = right;
}
void KeyController::onAPress(void (*a)())
{
    aCallBack = a;
}
void KeyController::onBPress(void (*b)())
{
    bCallBack = b;
}
bool KeyController::buttonEventListener()
{
    if (upCallBack != NULL && isUpPressed())
        upCallBack();
    if (downCallBack != NULL && isDownPressed())
        downCallBack();
    if (leftCallBack != NULL && isLeftPressed())
        leftCallBack();
    if (rightCallBack != NULL && isRightPressed())
        rightCallBack();
    if (aCallBack != NULL && isAPressed())
        aCallBack();
    if (bCallBack != NULL && isBPressed())
        bCallBack();
}