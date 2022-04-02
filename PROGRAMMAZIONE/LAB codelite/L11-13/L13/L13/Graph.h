#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>

typedef struct edge { int v; int w; int wt; } Edge;

typedef struct graph *Graph;

Graph GRAPHinit(int V);
void  GRAPHfree(Graph G);
Graph GRAPHload(FILE *fin,Edge **a);
void  GRAPHstore(Graph G, FILE *fout,Edge *a);
int   GRAPHgetIndex(Graph G, char *label);
void  GRAPHinsertE(Graph G, int id1, int id2, int wt);
void  GRAPHremoveE(Graph G, int id1, int id2);
void  GRAPHedges(Graph G, Edge *a);
int* findEtoDel(Graph G,Edge*e);

void printvertexbyEdge(Graph G,Edge * a,int id);
void Dagcreate(Graph G,Edge **a,int *del);
void camminiMax(Graph G,Edge* a);
#endif
