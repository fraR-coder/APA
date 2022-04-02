#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include "invArray.h"

#define EQUIP_SLOT 8


struct invArray_s{         //tabinv è puntatore a questa struct
    int nInv;
    
    inv_t *vettInv;
    
};




tabinv invArray_init(){
    
    tabinv a=calloc(1,sizeof(struct invArray_s));
    
    return a;
    
}


/* lettura e scrittura su file */
void invArray_read(FILE *fp, tabinv invAp){
    
 
        fscanf(fp,"%d",&invAp->nInv);
        invAp->vettInv=calloc(invAp->nInv,sizeof(inv_t));
        
           for(int i=0;i<invAp->nInv;i++){
               leggi_oggetto(fp,&invAp->vettInv[i]);
    }
    
}

/* stampa un unico oggetto selezionato da indice (nel vettore) */
void invArray_printByIndex(FILE *fp, tabinv invAp, int index){
    
    stampa_oggetto(fp,&invAp->vettInv[index]);
    
    
    
}
/* ritorna puntatore a oggetto selezionato da indice (nel vettore) */
inv_t *invArray_getByIndex(tabinv invAp, int index){
    
    return &invAp->vettInv[index];
    
}
/* ritorna indice (nel vettore) a oggetto selezionato da nome */
int invArray_searchByName(tabinv invAp, char *name){
    
    if(invAp==NULL) return -1;
    
    for(int i=0;i<invAp->nInv;i++){
        if(strcmp(invAp->vettInv[i].nome,name)==0) return i;
        
    }
                printf("non trovato\n");
                return -1;
        
}

void libera_inventario(tabinv invAp){

free(invAp->vettInv);
free(invAp);   
}

void stampa_inventario(FILE *fp, tabinv invAp){
    
    if(invAp==NULL) return;
    
    printf("INVENTARIO:\n");
    for(int i=0;i<invAp->nInv;i++){
    stampa_oggetto(fp,&invAp->vettInv[i]);
    
    }
}
 