#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXS 100
#define nomefile "elementi.txt"

#define DD 12
#define DP 30
#define NUM_DIAG 3
#define MAX_EL 5

float punt, max;
int programma[NUM_DIAG];
int best[NUM_DIAG];
    

typedef struct {
    
    char nome[MAXS];
    int type,in,out,prec,fin,diff;
    float val;
    int preso;
    
    
}Elemento;


typedef struct{
    
    int idE[MAX_EL];
    int ne;
    float punt;
    int diff;
    int acro_a;
    int acro_d;
    int seq;
    
}Diagonale;

typedef struct{
    
    Diagonale *diag_vett;
    int nd;
    
    
}Diagonali_t;



Diagonali_t *initD(){
    
    Diagonali_t *D=malloc(1*sizeof(Diagonali_t));
    D->nd=0;
    D->diag_vett=calloc(NUM_DIAG,sizeof(Diagonale));
    
    
    return D;
}

Elemento *leggi_file(int *n){
    Elemento *E;
    int N;
    FILE *fin=fopen(nomefile,"r");
    assert(fin!=NULL);
   
    fscanf(fin,"%d",&N);
    E=malloc(N*sizeof(Elemento));
    
    for(int i=0;i<N;i++){
        fscanf(fin,"%s %d %d %d %d %d %f %d",E[i].nome,&E[i].type,&E[i].in,&E[i].out,&E[i].prec,&E[i].fin,&E[i].val,&E[i].diff);
        E[i].preso=0;
    }
    
    *n=N;
    return E;
    
    
}

int valcmpr(Elemento E,Elemento A){
    
    if(E.val>A.val) return 1;
    
    if(E.val==A.val) return 0;
    
    return -1;    
}
int diffcmpr(Elemento E,Elemento A){
    
    if(E.diff>A.diff) return 1;
    
    if(E.diff==A.diff) return 0;
    
    return -1;    
}

void  ordinaPunt(Elemento *E,int n,int* punt_sort){
    
    Elemento max;
    int maxp;
    
    for(int i=0;i<n;i++){
        E[i].preso=0;
    }
   int i=0;
    while(i<n-1){
        max=E[0];
        maxp=0;
        
        for(int j=0;j<n;j++){
            if(E[j].preso==1) continue;
            if(valcmpr(E[j],max)>=0){
                max=E[j];
                maxp=j;
            }
        }
            E[maxp].preso=1;
            punt_sort[i]=maxp;
           
            i++;
        
        
    }
    

}
void  ordinaDiff(Elemento *E,int n,int* diff_sort){
    
    Elemento max;
    int maxp;
    
    for(int i=0;i<n;i++){
        E[i].preso=0;
    }
   int i=0;
    while(i<n-1){
        max=E[0];
        maxp=0;
        
        for(int j=0;j<n;j++){
            if(E[j].preso==1) continue;
            if(diffcmpr(E[j],max)>=0){
                max=E[j];
                maxp=j;
            }
        }
            E[maxp].preso=1;
            diff_sort[i]=maxp;
           
            i++;
        
        
    }
    

}


int partenza(Elemento E){
    
if(E.diff<=DD){
    if(E.prec==0){
        if(E.in==1){
            if(E.fin==0){
                return 1;
            }
           
        }
    }
    
}
    return 0;
}

int acrobatico(Elemento E){
    if(E.type==2) return 2;
    if(E.type==1) return 1;
    return 0;
    
}

int checkDD(int diff_d,int diff_p,int diff_to_add){
    
    if((diff_d+diff_to_add)>DD) return 0;
    if((diff_p+diff_to_add)>DP) return 0;
    
    return 1;
}
int in_sequenza(int primo,int secondo){
    
    return primo==secondo;
}

int checkSeq(Elemento E,Elemento A){
    
    if((E.type==2 || E.type==1) && (A.type==2 || A.type==1)) return 1;
    
    return 0;
}
int checkFinale(Elemento E){
    return E.fin;
}

void genera_prog(Elemento*E,Diagonali_t *D,int n){
    int i,j;
    int dd;
    int dp;
    int pos=0;
    int acro;
    int* punt_sort=malloc(n*sizeof(int));
    int* diff_sort=malloc(n*sizeof(int));
    ordinaPunt(E,n,punt_sort);
    ordinaDiff(E,n,diff_sort);
 
    //creo prima diagonale con almeno 1 elemnto acro_a e vincoli rispettati
int found=0;
dd=dp=0;
j=0;
Diagonale diagC=D->diag_vett[j];
        while(found){
            
            
            if(pos==0){
              if(partenza(E[punt_sort[i]])){
                if(checkDD(dd,dp,E[punt_sort[i]].diff)){
                    diagC.idE[pos]=punt_sort[i];
                    dd+=E[punt_sort[i]].diff;
                    dp+=E[punt_sort[i]].diff;
                    if(acrobatico(E[punt_sort[i]])==2) diagC.acro_a=1;
                    if(acrobatico(E[punt_sort[i]])==1) diagC.acro_d=1;
                    i=0;
                    pos++;
                   
                }
              }
              i++;
            }
            if(pos>0){
                if(in_sequenza(E[diagC.idE[pos]].out,E[punt_sort[i]].in)){
                    if(checkDD(dd,dp,E[punt_sort[i]].diff)){
                        if(diagC.acro_a==0 && diagC.acro_d==0){
                            if(acrobatico(E[punt_sort[i]])==2){
                                diagC.idE[pos]=punt_sort[i];
                                dd+=E[punt_sort[i]].diff;
                                dp+=E[punt_sort[i]].diff;
                                diagC.acro_a=1;
                                if(checkFinale(E[punt_sort[i]]) break;
                                i=0;
                                pos++;
                            }
                            if(acrobatico(E[punt_sort[i]])==1){
                                diagC.idE[pos]=punt_sort[i];
                                dd+=E[punt_sort[i]].diff;
                                dp+=E[punt_sort[i]].diff;
                                diagC.acro_d=1;
                                if(checkFinale(E[punt_sort[i]]) break;
                                i=0;
                                pos++;
                            }
                        }
                        else{
                        diagC.idE[pos]=punt_sort[i];
                        dd+=E[punt_sort[i]].diff;
                        dp+=E[punt_sort[i]].diff;
                        if(checkFinale(E[punt_sort[i]]) break;
                        i=0;
                        pos++;
                        }
                        
                        if(checkSeq(E[diagC.idE[pos]],E[punt_sort[i]])) diagC.seq=1;
                
                        
                    }
                }
                i++;
             
        }
        
        if(pos>=MAX_EL) found=1;
        
        
        
}



int main()
{
    int N;
    int i,j;
    Elemento *E=leggi_file(&N);
    Diagonali_t *D=initD();
    
    
    
    
    int *sol=calloc(MAX_EL,sizeof(int));
    max=punt=0;
    
    genera_prog(E,D,N);
    



  




for( i=0;i<D->nd;i++){
    
         free(D->diag_vett[i].idE);
    }
    
    free(D->diag_vett);

    
    free(D);
    free(E);
	return 0;
}


