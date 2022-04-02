#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "LIST.h"

typedef struct nodo* link;
struct nodo{int val;link next;};

struct lista{
    link head;
    int n;
};

void f(LIST l,int *v,int n){
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        if(v[i]<min) min=v[i];
    }
    
    link p,x;
    link t=NULL; 
    for(x=l->head, p=NULL; x!=NULL;p=x,x=x->next){ 
    if(t!=NULL) free(t);
        if(x->val>min){
            l->n--;
            if(x==l->head){ 
                t=x;
                l->head=x->next;
                             
            }
            else{
                t=x;
                l->n--;
                p->next=x->next;
        
            }
            
        }
    }
    if(t!=NULL) free(t);
    
    
}




static link NEW(int v, link next) {
  link x = malloc(sizeof *x);
  if (x == NULL)
    return NULL;
  x->val = v;
  x->next = next;
  return x;
}

LIST creaLista(){
    
    LIST l=malloc(sizeof(*l));
    l->n=7;
    l->head=NEW(0,NULL);
    l->head=NEW(4,l->head);
    l->head=NEW(1,l->head);
    l->head=NEW(3,l->head);
    l->head=NEW(6,l->head);
    l->head=NEW(10,l->head);
    l->head=NEW(3,l->head);
    
    return l;
}

void stampaLista(FILE* fout, LIST l){
    link x=l->head;
    while(x!=NULL){
        fprintf(fout,"%d ",x->val);
        x=x->next;
    }
    fprintf(fout,"\n");
}



void libera(LIST l){
    link x;
    
    while(l->head!=NULL){
        x=l->head->next;
        free(l->head);
        l->head=x;
    }
    
}

