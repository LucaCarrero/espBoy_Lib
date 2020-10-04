#ifndef Pezzo_h
#define Pezzo_h

#include "Arduino.h"

#ifndef _U8G2LIB_HH
#include <U8g2lib.h>
#endif

class GameObject {
private:
    /* data */
    int x;
    int y;
    int h;
    int b;
public:
    GameObject(int,int,int,int);
    virtual void disegna(U8G2 &t);
    int getX();
    int getY();
    int getH();
    int getB();
    void setX(int X);
    void setY(int Y);
    void setH(int H);
    void setB(int B);
    void setXY(int,int);
};
#endif
