#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include "pg.h"
#include "inv.h"



/* lettura e scrittura su file */
int leggi_personaggio(FILE *fp, pg_t *pgp){
    int x;
    x=fscanf(fp,"%s %s %s",pgp->cod,pgp->nome,pgp->classe);
    leggi_stat(fp,&pgp->stat_b);
    pgp->stat_eq=pgp->stat_b;
    
    pgp->equip=equipArray_init();
    
    
    
    return x;
    
}
/* non essendo struct dinamica, pulisce chiamando il distruttire di equipArray */
void pg_clean(pg_t *pgp){
    
    if(pgp->equip==NULL) return;
    
    equipArray_free(pgp->equip);
}

void stampa_personaggio(FILE *fp, pg_t *pgp,tabinv invArray){
    
    int min;
    int i;
    
    fprintf(fp,"%s %s %s ",pgp->cod,pgp->nome,pgp->classe);
    if(equipArray_inUse(pgp->equip)>0){
        
        min=0;
        stampa_stat(fp,&pgp->stat_eq,min);
        equipArray_print(fp,pgp->equip,invArray);
    }
    else {
        min=INT_MIN;
    
    
    stampa_stat(fp,&pgp->stat_b,min);
    }


 
}
/* modifica personaggio aggiungendo/togliendo un equipaggiamento selezionato da inventario:
di fatto e' sufficiente chiamare l'opportuna funzione dal modulo equipArray */
void pg_updateEquip(pg_t *pgp, tabinv invArray){
    
    int scelta;
    int indice;
    stat_t eq;
    inv_t * oggetto;
    printf("personaggio trovato\n");
    stampa_personaggio(stdout,pgp,invArray);
    equipArray_update(pgp->equip,invArray);  
    
    pgp->stat_eq=pgp->stat_b;
    for(int i=0;i<EQUIP_SLOT;i++){
     indice=equipArray_getEquipByIndex(pgp->equip,i);
     if(indice!=-1){
    oggetto= invArray_getByIndex(invArray,indice);
    
    eq=get_stat(oggetto);
    
    
    
    pgp->stat_eq=aggiorna_stat(pgp->stat_eq,eq);
     }
    }
}
