#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#include "inv.h"






void leggi_oggetto(FILE *fi, inv_t *invp){
  
    fscanf(fi,"%s %s", invp->nome,invp->tipo);
    leggi_stat(fi,&invp->stat);
    
}
void leggi_stat(FILE *f, stat_t *tmp){
    
    fscanf(f,"%d%d%d%d%d%d",&tmp->hp,&tmp->mp,&tmp->atk,&tmp->def,&tmp->mag,&tmp->spr);
        
}


 
 void stampa_oggetto(FILE *fp, inv_t *invp){
    
     printf("%s %s ",invp->nome,invp->tipo);
     stampa_stat(fp,&invp->stat,INT_MIN);
}


void stampa_stat(FILE *f ,stat_t *tmp,int min){

    
    fprintf(f,"%d %d %d %d %d %d\n",tmp->hp<min? 0:tmp->hp ,tmp->mp<min? 0:tmp->mp,tmp->atk<min? 0:tmp->atk,tmp->def<min? 0:tmp->def,tmp->mag<min? 0:tmp->mag,tmp->spr<min? 0:tmp->spr);
}

stat_t get_stat(inv_t *invp){
    
    return invp->stat;
}

stat_t  aggiorna_stat(stat_t b, stat_t e){
    
    b.atk+=e.atk;
    b.def+=e.def;
    b.mag+=e.mag;
    b.hp+=e.hp;
    b.mp+=e.mp;
    b.spr+=e.spr;
    
    return b;
     

    
}