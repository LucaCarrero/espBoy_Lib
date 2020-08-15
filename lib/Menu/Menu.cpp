#include <Menu.h>

Menu::Menu(){
    indice = 1;
}

//disegna il menù sullo schermo lcd
void Menu::disegnaM(U8G2 &t){
    uint8_t tit = ((t.getDisplayWidth()/2)-(t.getStrWidth(titolo)/2)); //calcola la x per centrare il titolo
    t.drawStr(tit,t.getFontAscent(),titolo); // disegna il titolo centrato nello scermo
    t.drawLine(0,t.getFontAscent()+1,t.getDisplayWidth(),t.getFontAscent()+1); // disegna una linea di separazione tra titolo e corpo del menù

    int h = t.getFontAscent()-t.getFontDescent(); 

    int startIndex = (page * PAGE_ELEMENT); // calcola l'offset dell'array in pase alla pagina e alle voci per pagina
    uint8_t elemToPrint = voiceNumber - startIndex < PAGE_ELEMENT ? voiceNumber - startIndex : PAGE_ELEMENT; // calcola quanti elementi per pagina solo disponibili nell'array delle voci
    
    t.drawStr(0,(indice*h*2)+1,">"); // disegna la posizione dell'indice con il carattere ">"
    for(int i = 1; i< elemToPrint+1 ; i++){// ciclo per disegnare le voci del menù
      
      uint8_t d = t.getStrWidth("> "); // calcola la x di partenza delle voci
      if(i == indice){
         t.drawStr(d,(i*h*2)+1,s[i-1+startIndex]+posizionScrolSelected); //disegna la voce selezionata con un ofzset di scorrimento se usato

        if(strlen(s[i-1+startIndex]) == posizionScrolSelected -1)  // azzera la posizione di scroll se arrivata alla fine della stringa della voce selezzionata
              posizionScrolSelected = 0;    
      }else
      {
        t.drawStr(d,(i*h*2)+1,s[i-1+startIndex]);// disegna tutte le altre voci
      }
    } 
}

//gestisce l'incremento dell'indice
void Menu::incIndide(){
  if( (page * PAGE_ELEMENT) + (indice) == voiceNumber) { //controlla che l'indice sia sull'ultimo elemento
     return;
  }else if(indice == PAGE_ELEMENT ){ //controlla se l'indice è sull'ultima voce della pagina in tal caso resetta l'indice e aumenta la pagina
    indice = 1;
    page++;
  }else{  //
    indice++;
    posizionScrolSelected = 0;
  }
}

//gestisceil decremento dell'indice
void Menu::decIndice(){
   if((page * PAGE_ELEMENT) == 0 && indice == 1){//controlla che l'indice sia sul primo elemento
     return;
  }else if( indice == 1 ){  //controlla se l'indice è sulla prima voce della pagina in tal caso resetta l'indice e decremanta la pagina
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

void Menu::setMenuItem(char **item, int numberOfVoice){ // imposta l'elenco delle voci del menu
  s = item;
  voiceNumber = numberOfVoice;
}

void Menu::setTitle(char * title){ // imposta il titolo del menù
    titolo = title;
}

void Menu::scrolSelectedVoice(uint8_t unit){ // sposta virtualmente di n posizioni la partenza della stringa
   posizionScrolSelected += unit;
}

char * Menu::getSelectedVoice(){ // ritorna la voce puntata dall'indice nella pagina corrente
  return s[(page * PAGE_ELEMENT) + (indice-1)];
}