#ifndef Menu_h
#define Menu_h

#include "Arduino.h"

#include <U8g2lib.h>
#define PAGE_ELEMENT 3

/*
    l'array delle voci per essere paginato viene trattato
    come se fosse una matrice, page gestisce la riga mentre
    indice decide la colonna sulla riga.
*/
class Menu {
private:
    char **s; // array delle voci del menù
    int voiceNumber;  // numero delle voci
    char *titolo; // titolo del menù
    uint8_t indice; // indice della voce selezionata nella pagina corrente
    int posizionScrolSelected = 0; // offset per lo scorrimento della voce selezionata
    int page = 0; // pagina corrente
public:
    void disegnaM(U8G2 &t);
    Menu();
    void incIndide();
    void decIndice();
    int getInd();
    void setMenuItem(char **item,int numberOfVoice );
    void scrolSelectedVoice(uint8_t unit );
    char * getSelectedVoice();
    void setTitle(char * title);
};
#endif