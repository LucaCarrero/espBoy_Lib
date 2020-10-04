#ifndef Pezzo_h
#define Pezzo_h

#include "Arduino.h"

#ifndef _U8G2LIB_HH
    #include <U8g2lib.h>
 #endif

/*
    Classe di base su cui basare gli oggetti di gioco.
    Estendendo questa classe si ha la possibiltà di gestire di usufruire di alcuni metodi relativi alla gestione delle cordinate.
    Per la scelta di cosa disegnare a schermo si totalmente totalmente liberisi può gestire tramite metodi esterno o fancendo l'override del metodo disegna.
*/
class GameObject {
private:
    /* attributi relativi alle cordinate e alle dimensioni dell'oggetto */
    int x;
    int y;
    int h;
    int b;
public:
    GameObject(int,int,int,int);

    #ifndef _U8G2LIB_HH
    // metodo da override per castomizzare casa disegnare sul display
     virtual void disegna(U8G2 &t);
    #endif
    
    //getter degli attributi della classe
    int getX();
    int getY();
    int getH();
    int getB();

    //setter degli attributi della classe
    void setX(int X);
    void setY(int Y);
    void setH(int H);
    void setB(int B);
    void setXY(int,int);
};
#endif
