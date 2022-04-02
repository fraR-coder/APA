#ifndef GRAPH_HclTabCtrl
#define GRAPH_H
#include <stdio.h>

#include "tabella_di_simboli.h"

typedef enum{
    matrice,lista
}struttura;

typedef struct edge { int n1; int n2; int flusso; } Edge;

typedef struct graph_s *Graph;



Graph GRAPHinit(int V);
void  GRAPHfree(Graph G);
Graph GRAPHload(ST *st, FILE *fin,int argc, char **argv);
void  GRAPHprintf(Graph G, FILE *fout,struttura k);

void GRAPHelencaArchi(Graph G,ST st,FILE *fout);
int EDsearchbyIndex(Graph G,int indice,int N);
void EDprintbyIndex(Graph G, int N,ST st,int parametri);

Graph GRAPHconvert(Graph G);
int GRAPHadiacenza(Graph G,int a,int b,int c);
#endif