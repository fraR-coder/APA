#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include "pgList.h"



//typedef struct pgList_s *pgList_t;
typedef struct nodo* link;
typedef struct nodo{        //NODO DELLA LISTA CONTIENE VAL (PERSONAGGIO)  E LINK nodoPg_t
    pg_t personaggio;
    
    link next; 
    
}nodoPg_t;


 struct pgList_s{    //LISTA CON PUNTATORI AI NODI E NUMERO NODI TabPg_t
    
    link head;
    link tail;
    int nPg;
    
}tabPg_t;



link  new_node(pg_t val , link next){
    
    link x=(link)malloc(sizeof(nodoPg_t));
    if(x==NULL) return NULL;
    
    x->personaggio=val;
    x->next=next;
    

    return x;
}

/* creatore e distruttore */
pgList_t pgList_init(){
    
    pgList_t listap=calloc(1,sizeof(*listap));
    listap->nPg=0;
     listap->head=listap->tail=NULL;
    
    return listap;
    
    
}
void pgList_free(pgList_t pgList){
    
    link x,p;
    for(x=pgList->head;x!=NULL;x=x->next){
        p=x->next;
        pg_clean(&x->personaggio);
        free(x);
        x=p;
    }
    free(pgList);
    
    
}

/* lettura e scrittura su file */
void pgList_read(FILE *fp, pgList_t pgList){
    
    pg_t pers;
  
     //se lista vuota
       
    
    while(leggi_personaggio(fp,&pers)==3){
        pgList_insert(pgList,pers);
        pgList->nPg++;
        
        
    }
  
    
    
}
void pgList_print(FILE *fp, pgList_t pgList, tabinv invArray){
    
     printf("PERSOANGGI:\n");
    
    link h=pgList->head;
    if(h==NULL) printf("lista vuota");
    
    while(h!=NULL){
        
  stampa_personaggio(fp,&h->personaggio,invArray);
        
        h=h->next;
    }
    
}

/* inserimento di un nuovo personaggio */
void pgList_insert(pgList_t listap, pg_t pg){
    
       if(listap->head ==NULL){
          
           listap->head = listap->tail=new_node(pg,NULL);
        }
    
        //inserzione in coda
        else{
        listap->tail->next=new_node(pg,NULL);
        listap->tail=listap->tail->next;
        }
        
       
        
    
}
/* cancellazione con rimozione */
void pgList_remove(pgList_t pgList, char* cod){
    
    link x,prev=NULL;
    
    
    if(pgList->head==NULL) return;

      
       for(x=pgList->head;x!=NULL; prev=x,  x=x->next){
           
        if(strcmp(x->personaggio.cod,cod)==0){
            break;
        }
       
       }
       
       
      if(x==pgList->head){
          pgList->head=x->next;
          pg_clean(&x->personaggio);
          free(x);
      }
      
      else if(x==pgList->tail){
          prev->next=NULL;
          pgList->tail=prev;
         pg_clean(&x->personaggio);
         free(x);
      }
      else if(x==NULL){
          printf("non trovato");
      }
      else{
          prev->next=x->next;
          pg_clean(&x->personaggio);
          free(x);
          
      }
      
    
    
}
/* ricerca per codice, ritornando il puntatore */
pg_t *pgList_searchByCode(pgList_t listap, char* cod){
   
    link x;
    link p=NULL;
   
    if(listap->head==NULL){
        printf("lista vuota\n");
        return NULL;
    }
    
    for(x=listap->head;x!=NULL; x=x->next){
        if(strcmp(x->personaggio.cod,cod)==0) {
            
                  
            return &(x->personaggio);
        }
        
    }
    printf("non trovato");
    return NULL;

}

void aggiungi_personaggio(pgList_t pgList){
    
    pg_t pg;
    printf("dati personaggio da aggiungere:\n");
    
    leggi_personaggio(stdin,&pg);
    
    pgList_insert(pgList,pg);
}


    
