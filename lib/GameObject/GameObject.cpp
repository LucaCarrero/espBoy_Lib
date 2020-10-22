#include "GameObject.h"

GameObject::GameObject(int x, int y, int b , int h){
    GameObject::x = x;
    GameObject::y = y;
    GameObject::b = b;
    GameObject::h = h;    
}

GameObject::GameObject(){
    GameObject::x = 0;
    GameObject::y = 0;
    GameObject::b = 0;
    GameObject::h = 0;    
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

int GameObject::collideWhit(GameObject &r2) {
    if (GameObject::x + GameObject::b/2 < r2.getX() - r2.getB()/2) return 0;
    if (GameObject::x - GameObject::b/2 > r2.getX() + r2.getB()/2) return 0;
    if (GameObject::y + GameObject::h/2 < r2.getY() - r2.getH()/2) return 0;
    if (GameObject::y - GameObject::h/2 > r2.getY() + r2.getH()/2) return 0;
    return 1;
}

