#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "ST.h"

#define F1 "grafo4.txt"

int main(int argc, char **argv)
{
    FILE *fin;
    fin=fopen(F1,"r");
    if(fin==NULL) exit(1);
    Edge *a;
    int *toDel;
  
    
   
    
    Graph G=GRAPHload(fin,&a);
   
  

  
  GRAPHstore(G,stdout,a);

    toDel=findEtoDel(G,a);
   
  
    Dagcreate(G,&a,toDel);
    
    

    GRAPHstore(G,stdout,a);
    
    
    
    camminiMax(G,a);
    
    
	GRAPHfree(G);
    free(a);
    free(toDel);

	return 0;
}
