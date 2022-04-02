#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXS 100
#define nomefile "elementi.txt"

#define DD 10
#define DP 20
#define NUM_DIAG 3
#define MAX_EL 5

float punt, max;
int programma[NUM_DIAG];
int best[NUM_DIAG];
    

typedef struct {
    
    char nome[MAXS];
    int type,in,out,prec,fin,diff;
    float val;
    
    
}Elemento;


typedef struct{
    
    int *idE;
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
    D->diag_vett=calloc(1,sizeof(Diagonale));
    
    
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
    }
    
    *n=N;
    return E;
    
    
}

int in_sequenza(int primo,int secondo){
    
    return primo==secondo;
}

int check_diag(int *sol,int pos,Elemento *E){
    int i;
    int diff=0;
  
    for(i=0;i<pos;i++){
        diff+=E[sol[i]].diff;
        if(diff>DD) return 0;
    }
    
    return 1;
    
    
}

int check_elemento(int *sol,int pos,Elemento *E){
        
        if(pos==0){
            if(E[sol[pos]].prec==1) return 0;
            
            if(E[sol[pos]].in==0) return 0;
            
            return 1;
        }
        
        if(in_sequenza(E[sol[pos-1]].out,E[sol[pos]].in)) return 1;
        
        return 0;
}
    
    
void  genera_diag(int pos, Elemento *E, Diagonali_t *D,int *sol,int n) {

  int i,j;
  int acro=0; 
if(pos>0){
   if(check_diag(sol,pos,E)==0) return;
   
   for(j=0;j<pos;j++){
    if(E[sol[j]].type==2) {
        D->diag_vett[D->nd].acro_a++;
        acro=1;
    }
    if(E[sol[j]].type==1) {
        D->diag_vett[D->nd].acro_d++;
        acro=1;
    }
   }
   if(acro){
   
    
    D->diag_vett[D->nd].ne=pos;
    D->diag_vett[D->nd].acro_a=D->diag_vett[D->nd].acro_d=0;
    D->diag_vett[D->nd].idE=malloc(pos*sizeof(int));
    D->diag_vett[D->nd].punt=0.0;
    D->diag_vett[D->nd].diff=0;
    D->diag_vett[D->nd].seq=0;
    for(int j=0;j<pos;j++){
        D->diag_vett[D->nd].idE[j]=sol[j];
        D->diag_vett[D->nd].punt+=E[sol[j]].val;
        D->diag_vett[D->nd].diff+=E[sol[j]].diff;
        if(E[sol[j]].type==2) D->diag_vett[D->nd].acro_a++;
        if(E[sol[j]].type==1) D->diag_vett[D->nd].acro_d++;
        
        if(j<pos-1){
            if(E[sol[j]].type!=0 && E[sol[j+1]].type!=0)   D->diag_vett[D->nd].seq++;
        }
    }
    
  
    
    D->nd++;
    D->diag_vett=realloc(D->diag_vett,(2*D->nd)*sizeof(Diagonale));
    
   
    
    if(E[sol[pos-1]].fin==1){
        return;
    }
   }
}

if(pos>=MAX_EL){
  
    return;
}

  
  for (i = 0; i <n ; i++) {
   
    sol[pos] = i;
    if(check_elemento(sol,pos,E)==0) continue;
    
   genera_diag(pos+1, E,D, sol,n);
  }
  return;
}

int check_progr(Elemento *E,Diagonali_t *D,int pos){
    
    int i;
    int diff=0;
    int a,d;
    float p=0;
    Diagonale tmp;
    int last;
    a=d=0;
    punt=0;
    int s=0;
    for(i=0;i<pos;i++){
        diff+=D->diag_vett[programma[i]].diff;
        if(diff>DP) return 0;
        
        a+=D->diag_vett[programma[i]].acro_a;
        d+=D->diag_vett[programma[i]].acro_d;
       
        
        if(D->diag_vett[programma[i]].seq !=0) s=1 ;
        
      
    
        punt+=D->diag_vett[programma[i]].punt;
        
         
    }
    
   
    if(s!=1) return 0;
    if(a==0 || d==0) return 0;
    
   for(i=0;i<pos;i++){
        tmp=D->diag_vett[programma[i]];
        last=tmp.ne -1;
        if(E[tmp.idE[last]].fin==1){
            if(E[tmp.idE[last]].diff>=8){
                punt-=tmp.punt;
                punt+= (tmp.punt)*1.5;
                return 1;
            }
        }
    }
    
    return 1;
}


void genera_prog(Elemento *E, Diagonali_t *D,int pos,int start){
    int i;
    
    
    if (pos >= NUM_DIAG) {
        if (check_progr(E, D, pos)){
        
        if (punt> max) {
        
        max=punt;
        for(int j=0;j<pos;j++){
            best[j]=programma[j];
        }
      
        }
        }
    return;
  }

  
   for(i=start;i<D->nd;i++) {
  
    programma[pos] = i;
    genera_prog(E, D, pos+1,i);
  }


}


int main()
{
    int N;
    int i,j;
    Elemento *E=leggi_file(&N);
    Diagonali_t *D=initD();
    
    int *sol=calloc(MAX_EL,sizeof(int));
    max=punt=0;
    
    
    genera_diag(0,E,D,sol,N);  
    
    printf("%d\n",D->nd);
  /*  for(int i=0;i<20;i++){
        printf("diagonale %d\n %f %d\n ",i+1,D->diag_vett[i].punt,D->diag_vett[i].diff);
        for(int j=0;j<D->diag_vett[i].ne;j++){
            printf("%s  \n",E[D->diag_vett[i].idE[j]].nome);
        }
    }
   */ 
     genera_prog(E, D,0,0);

printf("DD %d   DP %d\n TOT  punteggio:%.3f\n",DD,DP,max);
 for(i=0;i<NUM_DIAG;i++) {
      
      printf("DIAGONALE %d --punteggio:%.3f -- difficolta:%d\n",i+1 , D->diag_vett[best[i]].punt,D->diag_vett[best[i]].diff);
      printf("%d\n",best[i]);
      for(j=0;j<D->diag_vett[best[i]].ne;j++){
        printf("%s ", E[D->diag_vett[best[i]].idE[j]].nome);
      }
      printf("\n");
    }
  




for( i=0;i<D->nd;i++){
    
         free(D->diag_vett[i].idE);
    }
    
    free(D->diag_vett);

    
    free(D);
    free(E);
	return 0;
}

