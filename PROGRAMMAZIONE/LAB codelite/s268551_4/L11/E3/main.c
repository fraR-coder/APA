#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DBG 1


#include "grafo.h"
#include "tabella_di_simboli.h"

int main(int argc, char **argv)

{
    int a,b,c;
    assert(argc==2);
    assert(argv[1]!=NULL);
    FILE *fi=fopen(argv[1],"r");
    assert(fi!=NULL);
    
    ST st;
    Graph G;
    
    G=GRAPHload(&st,fi,argc,argv);
    
#if DBG  
 GRAPHprintf(G,stdout,0);
 
#endif

int comando=-1;



while(comando!=0){
    printf("MENU\nordine alfabetico-1\nverifica adiacenza-2\ngenera lista-3\nfine-0\n");
    scanf("%d",&comando);
    switch (comando){
        
        case 0:
            break;
        
        case 1:
        st=ordina_alphabetico(st);
        GRAPHelencaArchi(G,st,stdout);
        break;
        
        case 2:
        printf("dimmi tre veritci \n");
        scanf("%d%d%d",&a,&b,&c);
        if(GRAPHadiacenza(G,a,b,c) )printf("sono adiacenti a coppie \n");
        
        break;
        
        case 3:
            G=GRAPHconvert(G);
            GRAPHprintf(G,stdout,1);
         break;
    }
}

    

   
   
   
   
   
   GRAPHfree(G);
   STfree(st);
    
	return 0;
}
  
  
  


