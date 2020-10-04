#include "GameObject.h"

GameObject::GameObject(int x, int y, int b , int h){
    GameObject::x = x;
    GameObject::y = y;
    GameObject::b = b;
    GameObject::h = h;    
}

int GameObject::getX(){
   return x;
}

int GameObject::getY(){
   return y;
}

int GameObject::getB(){
   return b;
}

int GameObject::getH(){
   return h;
}

void GameObject::setX(int X){
   GameObject::x =X;
}

void GameObject::setY(int Y){
   GameObject::y=Y;
}

void GameObject::setH(int X){
   GameObject::h =h;
}

void GameObject::setB(int Y){
   GameObject::b=b;
}

void GameObject::setXY(int nX,int nY){
   setX(nX);
   setY(nY);
}