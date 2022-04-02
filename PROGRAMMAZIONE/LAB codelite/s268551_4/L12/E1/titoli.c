#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <float.h>

#include "titoli.h"
#include "quotazioni.h"
#include "data.h"


#define MAXS 20

typedef struct{
    char *codice;
    float min,max;
    BST Q;
}titolo_s;


struct nodotitolo{
   titolo_s titolo;
    NODE next;
    
};

struct listatitoli{
    int N;
    NODE h;
};

LIST LISTinit(){
    LIST L=malloc(1*sizeof(*L));
    L->N=0;
    L->h=NULL;
    return L;
    
}
void LISTfree(LIST L){
    NODE x=L->h;
    NODE p;
    while(x!=NULL){
        p=x->next;
        free(x->titolo.codice);
        BSTfree(x->titolo.Q);
        free(x);
        x=p;
    }
    
}

static NODE NEWnode( titolo_s t, NODE next) {
  NODE x = calloc(1, sizeof(*x));
  
  x->titolo=t;
  x->next=next;
  return x;
}

NODE LISTsearch_by_code(LIST L,NODE *p,char *codice){
    
    NODE x=L->h;
   
        while(x!=NULL){
           
            if(strcmp(x->titolo.codice,codice)>=0){
               
                break;
            }
            *p=x;
            x=x->next;
            
        }
        
        
        return x;
}

static LIST inserisci_in_listaOrd(LIST L,titolo_s t){
    
    NODE x;
    NODE p=NULL;
    if(L->h==NULL){
        L->h=NEWnode(t,NULL);
    }
    else{
        x=LISTsearch_by_code(L,&p,t.codice);
       
        if(p==NULL) {
            L->h=NEWnode(t,L->h);
        }
        else if(x==NULL){
            x=NEWnode(t,NULL);
            p->next=x;
        }
        else{
            p->next=NEWnode(t,x);
        }
            
        }
        
    return L;

}


static titolo_s leggi_titolo(LIST L,FILE *fin){
    char tmp[MAXS];
    int n;
    titolo_s l;
    data_s data;
    int valore;
    int quantita;
    float quotazione;
    fscanf(fin,"%s %d",tmp,&n);
    l.codice=strdup(tmp);
    
    l.Q=BSTinit(n);
   
    for(int i=0;i<n;i++){
     data=leggi_data(fin);
     fscanf(fin,"%d %d",&valore,&quantita);
     BSTinsert(l.Q,data,quantita,valore,&quotazione);
     if(quotazione>l.max) l.max=quotazione;
     if(quotazione<l.min) l.min=quotazione;
     
    }
    
    return l;

    
}

void leggi_file(LIST L,FILE *fin){
    int i;
    titolo_s t;
     int N;
    if(fscanf(fin,"%d",&L->N)!=1) exit(1);
    for(i=0;i<L->N;i++){
        t=leggi_titolo(L,fin);
        L=inserisci_in_listaOrd(L,t);
    }
    
    
}

static void stampa_titolo(NODE x,FILE *fout){
    printf("%s \n",x->titolo.codice);
    BSTprint(x->titolo.Q,fout);
}

void stampa_lista(LIST L,FILE*fout){
    
    NODE x=L->h;
    while(x!=NULL){
        stampa_titolo(x,fout);
        x=x->next;
    }
    
    
}

float cerca_quotazione(NODE x,data_s data){
    
    return BSTsearchByDate(x->titolo.Q,data);
    
}

 void cercaMaxMin(data_s d1,data_s d2,NODE x){
     int  cmp=compara_date(d1,d2);
     float max=0;
     float min=FLT_MAX;
    if(cmp==0) {
        printf("%f\n",BSTsearchByDate(x->titolo.Q,d1));
    }
    if(cmp>0){
        BSTsearchMaxMin(x->titolo.Q,d2,d1,&max,&min);
        printf("MAX %f MIN %f\n",max,min);
    }
    else {
        BSTsearchMaxMin(x->titolo.Q,d1,d2,&max,&min);
        printf("MAX %f MIN %f\n",max,min);
    }
    
    
        

    
     
 }
 
float getMAX(NODE x){
    
    return x->titolo.max;
    
}
 float getMIN(NODE x){
     return x->titolo.min;
 }
 
  void bilanciamento(NODE x,int S){
      
      BSTbalance(x->titolo.Q,S);
  }