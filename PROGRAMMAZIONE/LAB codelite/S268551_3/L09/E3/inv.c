#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#include "inv.h"


#define FI "inventario.txt"

void carica_inventario(tabInv invp){
    int i;
  
    
    FILE *fi;
    fi=fopen(FI,"r");
    assert(fi!=NULL);
    
    fscanf(fi,"%d",&invp->nInv);
    
    invp->vettInv=(inv_t *)malloc(invp->nInv * sizeof(inv_t));
    assert(invp->vettInv !=NULL);
    
    for(i=0;i<invp->nInv;i++){
        fscanf(fi,"%s %s", invp->vettInv[i].nome,invp->vettInv[i].tipo);
        
        invp->vettInv[i].stat=leggi_stat(fi);        
    }
    

    
    
    
}

stat_t leggi_stat(FILE *f){
    
    stat_t tmp;
    
    fscanf(f,"%d%d%d%d%d%d",&tmp.hp,&tmp.mp,&tmp.atk,&tmp.def,&tmp.mag,&tmp.spr);
    
    return tmp;
    
}

void libera_inventario(tabInv invp){
    
    free(invp->vettInv);
     free(invp);
}

void stampa_inventario(tabInv invp){
    
    printf("INVENTARIO:\n");
    for(int i=0;i<invp->nInv;i++){
       stampa_oggetto(invp->vettInv[i]);
    }
}
void stampa_oggetto(inv_t oggetto){
     printf("%s %s ",oggetto.nome,oggetto.tipo);
     stampa_stat(oggetto.stat,INT_MIN);
}
void stampa_stat(stat_t tmp,int min){
    
    printf("%d %d %d %d %d %d\n",tmp.hp<min? 0:tmp.hp ,tmp.mp<min? 0:tmp.mp,tmp.atk<min? 0:tmp.atk,tmp.def<min? 0:tmp.def,tmp.mag<min? 0:tmp.mag,tmp.spr<min? 0:tmp.spr);
}
