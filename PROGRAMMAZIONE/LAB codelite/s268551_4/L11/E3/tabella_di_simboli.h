#ifndef ST_H
#define ST_H

#include <stdio.h>

typedef struct symboltable * ST;

ST  STinit();
void STfree(ST st);

int   STcheck_duplicati(ST st,char * nome,int dim);

void  STinsert(ST st, char * nome, char* id,int indice);

char *STsearchByIndex(ST st, int indice);
char *STgetByIndex(ST st, int i);
int STsearchByName(ST st, char *name);

ST ordina_alphabetico(ST st);

int STprintsingolo(ST st,int i,int parametri);
#endif