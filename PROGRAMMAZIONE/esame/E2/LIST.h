#ifndef LIST_H
#define LIST_H
#include <stdio.h>

typedef struct lista*LIST;

void f(LIST l,int *v,int n);
LIST creaLista();
void libera(LIST l);
void stampaLista(FILE *fout, LIST l);

#endif