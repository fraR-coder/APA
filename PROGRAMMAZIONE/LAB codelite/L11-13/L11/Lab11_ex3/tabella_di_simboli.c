#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Vmax 100
#define MAXS 30
#include "tabella_di_simboli.h"

typedef struct elab_s{
    int N;
    char *nome;
    char *id;
    
}Elaboratore;


struct symboltable{
    int V;
    
    Elaboratore *rete;
    
};




ST STinit(){
    
    ST  st_p=malloc(sizeof(*st_p));
    
    
   st_p->V=0;
   st_p->rete=malloc(Vmax*sizeof(Elaboratore));
   for(int i=0;i<Vmax;i++){

   st_p->rete[i].N=-1;
   }
    return st_p;
    
}

void STfree(ST st){
    int i;
    for(i=0;i<st->V;i++){
    free(st->rete[i].id);
    free(st->rete[i].nome);
    }
    free(st->rete);
    free(st);
}

int   STcheck_duplicati(ST st,char * nome,int dim){
    int i;
    
    for(i=0;i<dim;i++){
        if(strcmp(st->rete[i].nome,nome)==0) return i;
    }
    return dim;
}

void  STinsert(ST st, char * nome, char* id,int indice){
    
    st->V++;
    st->rete[indice].nome=strdup(nome);
    st->rete[indice].id=strdup(id);
    st->rete[indice].N=indice;
    
    
}

char *STsearchByIndex(ST st, int indice){
     int i;
    
    for(i=0;i<st->V;i++)
    if(st->rete[i].N==indice) return st->rete[i].nome;
   
    return NULL;
    
}
char *STgetByIndex(ST st, int indice){
    
     
    
     return st->rete[indice].nome;
   
    return NULL;
    
}

int STsearchByName(ST st, char *name){
     int i;
    
    for(i=0;i<st->V;i++){
        if(strcmp(st->rete[i].nome,name)==0) return st->rete[i].N;
    }
    return -1;
    
}
int  STprintsingolo(ST st,int i,int parametri){
    
        switch(parametri){
            case(1):
            printf("%d ",st->rete[i].N);
            break;
            case(2):
            printf("%s %s",st->rete[i].nome,st->rete[i].id);
            break;
            default:break;
        }
    
    return st->rete[i].N;
}

ST ordina_alphabetico(ST st){
    
    char tmp[MAXS];
    char x[MAXS];
    char min[MAXS];
    int pos;
    int f;
    
 
    for(int i=0;i<st->V-1;i++){
     
        strcpy(min,STgetByIndex(st,i));
        pos=i;
         for( int j=i+1;j<st->V;j++){
            strcpy(x,STgetByIndex(st,j));
            
            if(strcmp(x,min)<0){
                strcpy(min,x);
                pos=j;
                f=1;
               
            }
            
         }
         if(f==1){
            strcpy(tmp,STgetByIndex(st,i));
            strcpy(st->rete[i].nome,STgetByIndex(st,pos));
             strcpy(st->rete[pos].nome,tmp);
             
             f= st->rete[pos].N;
             st->rete[pos].N=st->rete[i].N;
             st->rete[i].N=f;
             
             
             strcpy(tmp,st->rete[i].id);
             strcpy(st->rete[i].id,st->rete[pos].id);
             strcpy(st->rete[pos].id,tmp);
              
         }
         
    }
   
   return st;



}