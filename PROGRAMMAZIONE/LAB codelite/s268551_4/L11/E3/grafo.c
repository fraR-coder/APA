#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Vmax 100
#define MAXS 30

#include "grafo.h"
#include "tabella_di_simboli.h"


typedef struct node *link;
struct node { int v; int wt; link next; } ;

struct graph_s{
    
int V; int E; int **madj;link *ladj;
Edge *tabella;
};





static Edge* EDinit(int E){
    
    Edge *ed=malloc(E*sizeof(Edge));
    return ed;

}
static void EDfree(Edge * tabella){
    if(tabella!=NULL) return;
   
    free(tabella);
}

static int **MATRIXinit(int r, int c, int val) {
  int i, j;
  int **t = malloc(r * sizeof(int *));
  if (t==NULL)
    return NULL;

  for (i=0; i < r; i++) {
    t[i] = malloc(c * sizeof(int));
    if (t[i]==NULL)
      return NULL;
  }
  for (i=0; i < r; i++)
    for (j=0; j < c; j++)
      t[i][j] = val;
  return t;
}
static void MATRIXfree(int** m,int r){
    int i,j;
    for(i=0;i<r;i++){
        free(m[i]);
        }
        free(m);
    }

static void MATRIXprint(int **m,int r,int c,FILE *fout){
    int i,j;
    for (i=0; i < r; i++){
        for (j=0; j < c; j++){
            fprintf(fout,"%d ",m[i][j]);
            
        }
        printf("\n");
}
printf("\n\n");
}

static void LISTfree(link h,int V){
    link x;
    
    while(h!=NULL){
        x=h->next;
        free(h);
        h=x;
        
    }
    
}

static void LISTprint(Graph G,FILE *fout){
    link x;
    
        for(int j=0;j<G->V;j++){
           x=G->ladj[j];
           printf("%d || ",j);
            while(x!=NULL){
                
                printf("-%d-",x->v);
                x=x->next;
                
            }
            printf("\n");
            
            
        }
        
    
    
    
    
}

Graph GRAPHinit(int V){
    
    
          Graph G=(Graph)malloc(sizeof(*G));
        if(G==NULL) return NULL;
    
        G->V=V;
        G->E=0;
        G->madj=MATRIXinit(V,V,0);
        G->tabella=NULL;
        G->ladj=NULL;
    
    return G;

    
    

    
}
void  GRAPHfree(Graph G){
    
    
    MATRIXfree(G->madj,G->V);
    EDfree(G->tabella);
    if(G->ladj!=NULL){
        for(int i=0;i<G->V;i++){
             LISTfree(G->ladj[i],G->V);
        }
    

    free(G->ladj);
    
    }
    free(G);
    
}

Graph GRAPHload(ST *st, FILE *fin,int argc, char **argv){
    
    int V=0;
    int i=0;
    int j=0;
    int k=0;
    Graph G;
    ST x=STinit();
    int w;
    char id[MAXS], nome[MAXS];
    char test[200];


while(fgets(test,200,fin)!=NULL){
    i++;
}

G=GRAPHinit(2*i);
G->tabella=EDinit(i);
G->E=i;

fclose(fin);
fin=fopen(argv[1],"r");
 
   
while(fscanf(fin," %s %s ",nome,id)!=EOF){
    
       
        i=STcheck_duplicati(x,nome,V);
        if(i==V){
        STinsert(x,nome,id,V);
        V++;
       
        }
   
        fscanf(fin," %s %s %d",nome,id,&w);
        
        j=STcheck_duplicati(x,nome,V);
        if(j==V){
        STinsert(x,nome,id,V);
        V++;
        }
        
        G->madj[i][j]=w;
        G->madj[j][i]=w;
        
         
        
        G->tabella[k].flusso=w;
        G->tabella[k].n1=i;
        G->tabella[k].n2=j;
        k++;
      
        
     
    }
    
    G->V=V;
    *st=x;
    
    return G;
}

static void EDprint_singolo(Graph G,int i){
    
    printf("%d---%d |%d|\n",G->tabella[i].n1,G->tabella[i].n2,G->tabella[i].flusso);
    
    
}


 void EDprintbyIndex(Graph G, int N,ST st,int parametri){

    int a;
    int i=0;
    int indice;
    char tmp[MAXS];
    
    for(i=0;i<G->V;i++){
        strcpy(tmp,STgetByIndex(st,i));
        indice=STsearchByName(st,tmp);
         
        a=EDsearchbyIndex(G,indice,N);
        if (a==-1) continue;
        
      
        switch (parametri){
            case 1:
                printf("%d(%d) ",indice,a);
                break;
            case 2:
            printf("%d [%s] (%d) ",indice,tmp,a);
            break;
        }
        
    
        printf(" // ");
        
    
    } 
    

    printf("\n");
    
    
}

 int EDsearchbyIndex(Graph G,int indice,int N){
    
   
          if(G->madj[indice][N]!=0){
              return G->madj[indice][N];
          
      }       
        return -1;    
}


void  GRAPHprintf(Graph G, FILE *fout,struttura k){
    
    int i;
    printf("numero vertici V=%d  numero archi E=%d\n",G->V,G->E);
    
   
if(k==0){ 
    printf("matrice delle adiacenze\n");
    MATRIXprint(G->madj,G->V,G->V,fout);
   for(i=0;i<G->E;i++){
        EDprint_singolo(G,i);
    }
}
else{
    printf("lista delle adiacenze\n");
    LISTprint(G,fout);
}
}

void GRAPHelencaArchi(Graph G,ST st,FILE *fout){
    
    int N;
    printf("VERTICI ORDINATI e archi\n");
    for(int i=0;i<G->V;i++){
    
        
        N=STprintsingolo(st,i,1);
        
    printf("| ");
        EDprintbyIndex(G,N,st,1);
    }
     

    
}

static link NEW(int v, int wt, link next) {
  link x = malloc(sizeof *x);
  if (x == NULL)
    return NULL;
  x->v = v;
  x->wt = wt;
  x->next = next;
  return x;
}



Graph GRAPHconvert(Graph G){
    
    G->ladj=calloc(G->V, sizeof(link));
    int a;
    
    for(int i=0;i<G->V;i++){
        
        for(int j=0;j<G->V;j++){
            if(G->madj[i][j]!=0) {
                G->ladj[i]=NEW(j,G->madj[i][j],G->ladj[i]);
                G->ladj[j]=NEW(i,G->madj[i][j],G->ladj[j]);
            }
        }
                
    
    }
    
    return G;
    
    
    
}

static int EDcheckarcoM(Graph G,int v1,int v2){
    
  
    return G->madj[v1][v2];
    
}
static int EDcheckarcoL(Graph G,int v1,int v2,int v3){
    
    int found1=0;
    int found2=0;
    
    link x=G->ladj[v1];
    while(x!=NULL){
        if(x->v==v2) found1=1;
        if(x->v==v3) found2=1;
        x=x->next;
    }
    
    if(found1==0 || found2==0) return 0;
    
  
    return 1;
    
}
int GRAPHadiacenza(Graph G,int a,int b,int c){
    
   
    
/*    if(EDcheckarcoM(G,a,b)!=0){
          if(EDcheckarcoM(G,a,c)!=0){
                if(EDcheckarcoM(G,b,c)!=0){
                    return 1;
                }
          }
    }
return 0; 
 */
if(G->ladj==NULL) return 0;

if(a<0 || a>=G->V) return 0;

if( EDcheckarcoL(G,a,b,c)) return 1;
      
    

return 0;
}