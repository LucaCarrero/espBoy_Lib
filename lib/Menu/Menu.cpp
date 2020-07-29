#include <Menu.h>

Menu::Menu(){
    indice = 1;
}

void Menu::disegnaM(U8G2 &t){
    int tit = ((84/2)-(t.getStrWidth(titolo[0])/2));
    t.drawStr(tit,t.getFontAscent(),titolo[0]);
    t.drawLine(0,t.getFontAscent()+1,t.getDisplayWidth(),t.getFontAscent()+1);


    int h = t.getFontAscent()-t.getFontDescent(); 
    t.drawStr( t.getStrWidth(""),(indice*h*2)+1,"> ");
    for(int i = 1; i<4; i++){
      int d = t.getStrWidth("> ");
      if(i == indice){
         t.drawStr(d,(i*h*2)+1,s[i-1]+posizionScrolSelected);

        if(strlen(s[i-1]) == posizionScrolSelected) 
              posizionScrolSelected = 0;    
      }else
      {
        t.drawStr(d,(i*h*2)+1,s[i-1]);
      }
      
       
    }
    
}

void Menu::incIndide(){
   if(indice -1 < sizeof(s)/sizeof(s[0])){
    indice--;
    posizionScrolSelected = 0;
  } 
}

void Menu::decIndice(){
  if(indice - 1 >= 0){
    indice--;
    posizionScrolSelected = 0;
  } 
}

int Menu::getInd(){
  return indice;
}

void Menu::setMenuItem(char **item){
  s = item;
}

void Menu::scrolSelectedVoice(int unit){
   posizionScrolSelected += unit;
}