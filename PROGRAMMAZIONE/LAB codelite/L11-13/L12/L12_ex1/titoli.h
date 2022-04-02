#ifndef  Titoli_H
#define Titoli_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "data.h"
#include "quotazioni.h"

typedef struct listatitoli * LIST;

typedef struct nodotitolo* NODE ;

LIST LISTinit();
void LISTfree(LIST L);
 void leggi_file(LIST L,FILE *fin);
 void stampa_lista(LIST L,FILE*fout);
 NODE LISTsearch_by_code(LIST L,NODE *p,char *codice);
 float cerca_quotazione(NODE x,data_s data);
 void cercaMaxMin(data_s d1,data_s d2,NODE x);
 float getMAX(NODE x);
 float getMIN(NODE x);
 void bilanciamento(NODE x,int S);
 
#endif