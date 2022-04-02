#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define EQUIP_SLOT 8
#define MAXS 50

#include "equipArray.h"


struct equipArray_s{     
    
    int  inUso;
    int vettEq[EQUIP_SLOT];
    
} ;

/* creatore e disruttore */
equipArray_t equipArray_init(){
    
    equipArray_t eqAp=calloc(1,sizeof(struct equipArray_s));
    for(int i=0;i<EQUIP_SLOT;i++){
        eqAp->vettEq[i]=-1;
    }
    eqAp->inUso=0;
    return eqAp;
    
}

void equipArray_free(equipArray_t eqAp){
    
    if(eqAp==NULL) return;
    free(eqAp);
    
}

/* quanti equipaggiamenti sono in uso */
int equipArray_inUse(equipArray_t eqAp){
    
        if(eqAp==NULL) return 0;
        return eqAp->inUso;
    }
    


/* scrittura su file */
void equipArray_print(FILE *fp, equipArray_t eqAp, tabinv invAp){
    
    if(eqAp->inUso >0){
         for(int i=0;i<EQUIP_SLOT;i++) {
             if(eqAp->vettEq[i]!=-1){
                 invArray_printByIndex(fp,invAp,eqAp->vettEq[i]);
             }
        }
    }
    
}
/* modifica equipaggiamento scegliendo un oggetto da inventario */
void equipArray_update(equipArray_t eqAp, tabinv invAp){
    
    int scelta;
    char nome[MAXS];
    printf("vuoi aggiungere(1) o rimuovere (0) un oggetto?\n");
    scanf("%d",&scelta);
    
    if(scelta==1){
        if(eqAp->inUso>8) {
            printf("equipaggiamento completo\n");
            return;
        }
        printf("quale oggetto vuoi aggiungere?\n");
        scanf("%s",nome);
      
        
      scelta=  invArray_searchByName(invAp,nome);
      invArray_printByIndex(stdout,invAp,scelta);
      
      for(int i=0;i<EQUIP_SLOT;i++){
     
        if(eqAp->vettEq[i]==-1){
        eqAp->vettEq[i]=scelta;
        eqAp->inUso++;
        break;
        }
        
      }
      
        
        
        
    }
    
    else{
            if(eqAp->inUso<1) {
            printf("equipaggiamento vuoto\n");
            return;
            }
            printf("equipaggiamento attuale\n");
            for(int i=0;i<EQUIP_SLOT;i++){
            
                if(eqAp->vettEq[i]!=-1){
                invArray_printByIndex(stdout,invAp,eqAp->vettEq[i]);
                }
            } 
            printf("quale vuoi togliere?\n");
            scanf("%s",nome);
      
        
            scelta=  invArray_searchByName(invAp,nome);
            for(int i=0;i<EQUIP_SLOT;i++){
                if(eqAp->vettEq[i]==scelta){
                     invArray_printByIndex(stdout,invAp,eqAp->vettEq[i]);
                     eqAp->vettEq[i]=-1;
                     eqAp->inUso--;
                }
            }
    }
    
            
    
    
    
    
    
}
/* torna indice (nel vettore inventario) dell'oggetto in posizione index (0..EQUIP_SLOT-1) di equipArray */
int equipArray_getEquipByIndex(equipArray_t eqAp, int index){
    
    if(eqAp==NULL) return -1;
    if(index>=EQUIP_SLOT || index<0) return -1;
    
    return eqAp->vettEq[index];
    
}


