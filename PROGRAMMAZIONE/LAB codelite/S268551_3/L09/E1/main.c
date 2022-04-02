#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define NOME "att.txt"


typedef struct{
    int si,fi;
}elenco;



int leggi_file(elenco** attivita){
    
    elenco *s;
  
    int i;
    int N;
    FILE *fs=fopen(NOME,"r");
    if(fs==NULL) exit(1);
    
    fscanf(fs,"%d",&N);
    
    
   s=(elenco*)malloc(N*sizeof(elenco));
   
   
    
    for( i=0;i<N;i++){
        fscanf(fs,"%d %d",&s[i].si,&s[i].fi);
       
    }

    *attivita=s;
    fclose(fs);
    
    return N;
 
}

int check(int N, elenco *v, int *sol, int pos) {
  int i;

  for (i=0; i<pos; i++) {
    if (sol[i] == 1) {
      if (v[i].si < v[pos].fi && v[pos].si < v[i].fi)
        return 1;
    }
  }
  return 0;
}


int cerca_r(elenco *v,int N,int d,int *sol, int*bestsol,int pos,int dmax){
    
    
    if(pos>=N){
          if(d>dmax){
                dmax=d;
                for(int i=0;i<N;i++){
                    bestsol[i] = sol[i];
                }       
            }
        return dmax;
    }
    
    sol[pos]=0;
    dmax=cerca_r(v,N,d,sol,bestsol,pos+1,dmax);
    if (check(N, v, sol, pos)==0) {
    sol[pos] = 1;
    d+=v[pos].fi-v[pos].si;
    dmax=cerca_r(v,N,d,sol,bestsol,pos+1,dmax);
  }    
    
    return dmax;
}
void attSel(int N, elenco *v){
    
    int i;
    int dmax=0;
    int d=0;
    int pos=0;
    int *sol = calloc(N, sizeof(int));
    int *bestsol = calloc(N, sizeof(int));
    
    dmax=cerca_r(v,N,d,sol,bestsol,pos,dmax);
    
     printf("durata max %d\n", dmax);
  for (i=0; i<N; i++)
    if (bestsol[i])
      printf(" (%d,%d)", v[i].si, v[i].fi);
  printf("\n");

  free(sol);
  free(bestsol);

  return;
    
}


int main()
{
   elenco *attivita;
    int N;
  
    
    N=leggi_file(&attivita);
    
    for(int i=0;i<N;i++){
        printf("%d %d\n",attivita[i].si,attivita[i].fi);
    }
    
    attSel(N,attivita);
    
    
    
	free(attivita);
	return 0;
}

