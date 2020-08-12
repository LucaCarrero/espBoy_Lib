#include <Menu.h>

Menu::Menu(){
    indice = 1;
}

void Menu::disegnaM(U8G2 &t){
    uint8_t tit = ((t.getDisplayWidth()/2)-(t.getStrWidth(titolo[0])/2));
    t.drawStr(tit,t.getFontAscent(),titolo[0]);
    t.drawLine(0,t.getFontAscent()+1,t.getDisplayWidth(),t.getFontAscent()+1);

    int h = t.getFontAscent()-t.getFontDescent(); 

    int startIndex = (page * PAGE_ELEMENT);
    uint8_t elemToPrint = voiceNumber - startIndex < PAGE_ELEMENT ? voiceNumber - startIndex : PAGE_ELEMENT;
    
    t.drawStr(0,(indice*h*2)+1,">");
    for(int i = 1; i< elemToPrint+1 ; i++){
      
      uint8_t d = t.getStrWidth("> ");
      if(i == indice){
         t.drawStr(d,(i*h*2)+1,s[i-1+startIndex]+posizionScrolSelected);

        if(strlen(s[i-1+startIndex]) == posizionScrolSelected -1) 
              posizionScrolSelected = 0;    
      }else
      {
        t.drawStr(d,(i*h*2)+1,s[i-1+startIndex]);
      }
    } 
}

void Menu::incIndide(){
  if( (page * PAGE_ELEMENT) + (indice) == voiceNumber) {
     return;
  }else if(indice == PAGE_ELEMENT ){
    indice = 1;
    page++;
  }else{  
    indice++;
    posizionScrolSelected = 0;
  }
}
 
void Menu::decIndice(){
   if((page * PAGE_ELEMENT) == 0 && indice == 1){
     return;
  }else if( indice == 1 ){ 
    indice = 3;
    page--;
  }else{  
    indice--;
    posizionScrolSelected = 0;
  }
}

int Menu::getInd(){
  return indice;
}

void Menu::setMenuItem(char **item, int numberOfVoice){
  s = item;
  voiceNumber = numberOfVoice;
}

void Menu::scrolSelectedVoice(uint8_t unit){
   posizionScrolSelected += unit;
}

char * Menu::getSelectedVoice(){

  return s[(page * PAGE_ELEMENT) + (indice-1)];
}