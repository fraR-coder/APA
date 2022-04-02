#include <stdio.h>
#include <stdlib.h>


#include "LIST.h"



int main()
{
    int n=3;
    int* v=malloc(n*sizeof(int));
    v[0]=1; v[1]=2; v[2]=3;  
    printf("vettore:\n");
    for(int i=0;i<n;i++) printf("%d ",v[i]);
    LIST l=creaLista();
    printf("\nlista\n");
    stampaLista(stdout,l);
    
    f(l,v,n);
    printf("\nnuova lista\n");
    stampaLista(stdout,l);
    
    libera(l);
	
	return 0;
}
