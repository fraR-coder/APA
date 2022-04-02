#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "ST.h"
#include "Graph.h"

#define MAXC 30

typedef enum {DAG ,CYCLE}grafo;
struct graph {int V; int E; int **madj; ST tab; };

static       Edge EDGEcreate(int v, int w, int wt);
static int **MATRIXint(int r, int c, int val);
static void  insertE(Graph G, Edge e);
static void  removeE(Graph G, Edge e);
static int   pathR(Graph G, int v, int w, int *visited);
static void  bfs(Graph G, Edge e, int *time, int *pre, int *st);

static Edge EDGEcreate(int v, int w, int wt) {
  Edge e;
  e.v = v;
  e.w = w;
  e.wt = wt;
  return e;
}

static int **MATRIXint(int r, int c, int val) {
  int i, j;
  int **t = malloc(r * sizeof(int *));
  if (t == NULL)
    return NULL;
  for (i=0; i < r; i++) {
    t[i] = malloc(c * sizeof(int));
    if (t[i] == NULL)
      return NULL;
  }
  for (i=0; i < r; i++)
    for (j=0; j < c; j++)
      t[i][j] = val;
  return t;
}

Graph GRAPHinit(int V) {
  Graph G = malloc(sizeof *G);
  if (G == NULL)
    return NULL;
  G->V = V;
  G->E = 0;
  G->madj = MATRIXint(V, V, 0);
  if (G->madj == NULL)
    return NULL;
  G->tab = STinit(V);
  if (G->tab == NULL)
    return NULL;
  return G;
}

void GRAPHfree(Graph G) {
  int i;

  for (i=0; i<G->V; i++)
    free(G->madj[i]);
  free(G->madj);
  STfree(G->tab);
  free(G);
}

Graph GRAPHload(FILE *fin,Edge **a) {
  int V, i, id1, id2, wt;
  char label1[MAXC], label2[MAXC];
  Graph G;
  Edge *e;

    
  fscanf(fin, "%d", &V);
  G = GRAPHinit(V);

  for (i=0; i<V; i++) {
    fscanf(fin, "%s", label1);
    STinsert(G->tab, label1, i);
  }

  while(fscanf(fin, "%s %s %d", label1, label2, &wt) == 3) {
    id1 = STsearch(G->tab, label1);
    id2 = STsearch(G->tab, label2);
    if (id1 >= 0 && id2 >=0)
      GRAPHinsertE(G, id1, id2, wt);
  }
  
   e = malloc(G->E * sizeof(Edge));
  if (e == NULL)
    return NULL;
    
 GRAPHedges(G,e);
 
 *a=e;
 
  return G;
}

static void  insertE(Graph G, Edge e) {
  int v = e.v, w = e.w, wt = e.wt;

  if (G->madj[v][w] == 0)
    G->E++;
  G->madj[v][w] = wt;
}

void GRAPHstore(Graph G, FILE *fout,Edge *a) {
  int i;


  fprintf(fout, "numero vertici%d\n", G->V);
  for (i = 0; i < G->V; i++)
    fprintf(fout, "%s\n", STsearchByIndex(G->tab, i));

  for (i = 0; i < G->E; i++)
    fprintf(fout, "%s  %s %d\n", STsearchByIndex(G->tab, a[i].v), STsearchByIndex(G->tab, a[i].w), a[i].wt);

}

int GRAPHgetIndex(Graph G, char *label) {
  int id;
  id = STsearch(G->tab, label);
  if (id == -1) {
    id = STsize(G->tab);
    STinsert(G->tab, label, id);
  }
  return id;
}

void GRAPHinsertE(Graph G, int id1, int id2, int wt) {
  insertE(G, EDGEcreate(id1, id2, wt));
}

void GRAPHremoveE(Graph G, int id1, int id2) {
  removeE(G, EDGEcreate(id1, id2, 0));
}

static void  removeE(Graph G, Edge e) {
  int v = e.v, w = e.w;
  if(v*w<0) return;
  if (G->madj[v][w] != 0)
    G->E--;
  G->madj[v][w] = 0;
}

void  GRAPHedges(Graph G, Edge *a) {


  int v, w, E = 0;
  for (v=0; v < G->V; v++)
    for (w=0; w < G->V; w++)
      if (G->madj[v][w] != 0)
        a[E++] = EDGEcreate(v, w, G->madj[v][w]);
}


 static int Edgevoid(Edge e){
     if(e.v==0 && e.w==0 && e.wt==0) return 1;
     return 0;
 }
 static void addArcoBack(Edge *e,int v,int w,int wt){
     int i=0;
     while(Edgevoid(e[i])==0){
        i++;
     }
     
    e[i]=EDGEcreate(v,w,wt);
     
 }
 
 static void dfsR(Graph G,Edge e,int *time,int *pre,int*post,int*st,Edge * back,int *t){
     int i,j;
    
int v=e.v;
int w=e.w;


if(pre[w]==-1){
    pre[w]=(*time)++;
}
i=w;
     for(j=0;j<G->V;j++){
         if(G->madj[i][j]!=0){
             if(pre[j]==-1){
                 dfsR(G,EDGEcreate(i,j,1),time,pre,post,st,back,t);
             }
             else if(post[j]==-1){
                    addArcoBack(back,i,j,G->madj[i][j]);
                 }
             
         }
     }
     if(post[i]==-1){
          st[(*t)++]=w;
                post[i]=(*time)++;
               
            }


return;

}
 
static int GraphDfs(Graph G,int id,int*st){
    int v, time=0, *pre, *post, t=0;
  pre = malloc(G->V*sizeof(int));
  post = malloc(G->V*sizeof(int));
  

  Edge * archi_b=malloc(G->E *sizeof(Edge));

  
  for(v=0;v<G->E;v++) archi_b[v].v=archi_b[v].w=archi_b[v].wt=0;
  
  for (v=0; v < G->V; v++) {
    pre[v] = -1;
    post[v]=-1;
    st[v] = -1;
  }
  
    dfsR(G,EDGEcreate(id,id,1),&time,pre,post,st,archi_b,&t);
    
    for (v=0; v < G->V; v++) {
        if(pre[v]==-1)
            dfsR(G,EDGEcreate(v,v,1),&time,pre,post,st,archi_b,&t);
            
    }
    
 
free(pre);
free(post);


if(Edgevoid(archi_b[0])) {
    free(archi_b);
    return 1;
}
    free(archi_b);
    return 0;
}

static int * combR(Graph G, Edge *a,int* sol,int* val,int start,int pos,int i,int *find,int * del,int *max,int* st ){
    int k,j,g;
    int peso=0;
    
    
    if(pos==i){
        
        for(k=0;k<i;k++){
            removeE(G,a[sol[k]]);
        }
        
        if(GraphDfs(G,0,st)==1){
            *find=1;
           
           for(k=0;k<i;k++){
               peso+=a[sol[k]].wt;
           }
        
          if(peso>*max){
              *max=peso;
             for( g=0;g<i;g++)
             del[g]=sol[g];
            }
        }    
         for(k=0;k<i;k++){
            insertE(G,a[sol[k]]);
        }
        return del;
    }
    
    for(j=start;j<G->E;j++){
        sol[pos]=val[j];
        del=combR(G,a,sol,val,j+1,pos+1,i,find,del,max,st);
        
        
    }
    return del;
}


static int*  combinazioniRimozioni(Graph G,Edge*a,int*max){
    int *sol=malloc(G->E* sizeof(int));
    int *val=malloc(G->E *sizeof(int));
    int *st = malloc(G->V*sizeof(int));
    int i,start,pos,j;
    int find=0;
    
    int * del=(int *)malloc(G->E * sizeof(int ));
  
        for(j=0;j<G->E;j++) {
            del[j]=-1;
        }
    
    
    for(i=0;i<G->E;i++) {
        val[i]=i;
        sol[i]=-1;
    }

    if(GraphDfs(G,0,st)==1) find=1;

    
    for(i=1;i<G->E && find==0;i++){
       
        del=combR(G,a,sol,val,0,0,i,&find,del,max,st);
    }
    
    free(st);
    free(sol);
    free(val);
 return del;   
}

void printvertexbyEdge(Graph G,Edge * a,int id){
    
Edge e;
e=a[id];
  printf("%s %s\n",STsearchByIndex(G->tab,e.v),STsearchByIndex(G->tab,e.w));
    
}

int* findEtoDel(Graph G,Edge*e){

int * rimossi;
int max=0;
    
    rimossi=combinazioniRimozioni(G,e,&max);
int j=0;

if(max==0) {
    printf("non ci sono archi B, e' DAG\n");
    return rimossi;
}
printf("archi da rimuovere a peso massimo per avere DAG\n");

        while(j<G->E && rimossi[j]!=-1){
            printvertexbyEdge(G,e,rimossi[j]);
        j++;
        }
    printf("peso:%d\n",max);
    


return rimossi;



}







void Dagcreate(Graph G,Edge **a,int *del){
    int i;
    Edge * e;
    for(i=0;i<G->E;i++){
        if(del[i]==-1) break;
        removeE(G,(*a)[del[i]]);
    }

 e=malloc(G->E*sizeof(Edge));
    GRAPHedges(G,e);
    
    *a=e;
    
     

}

void maxPath(Graph G, int* st, int* ord, int* maxdist,int start){
    int i,j;
    int v;
    
       for( i=start;i>=0;i--){
         v=st[i];
         if(ord[v]==-1) continue;
         for(j=0;j<G->V;j++){
              if(G->madj[v][j]!=0){
                  if(maxdist[j]<maxdist[v]+G->madj[v][j]){
                      maxdist[j]=maxdist[v]+G->madj[v][j];
                      ord[j]=v;
                  }
                }
            }
     }
}


void camminiMax(Graph G,Edge* a){
    int*st = malloc(G->V*sizeof(int));
    int*ord=malloc(G->V*sizeof(int));
    int* maxdist=malloc(G->V*sizeof(int));
    int wt;
    int v,w;
    int i,j,k;
    GraphDfs(G,0,st);
    printf("ordinamento topologico dag\n");
    for( i=G->V-1;i>=0;i--)
    printf("%s  ",STsearchByIndex(G->tab,st[i]));
    printf("\n");
    
    
for( i=G->V-1;i>=0;i--){
    printf("%s sorgente:\n",STsearchByIndex(G->tab,st[i]));
    
     for( k=G->V-1;k>=0;k--){
        maxdist[k]=-1;
        ord[k]=-1;
    }
    
    ord[st[i]]=st[i];
    maxdist[st[i]]=0;
    maxPath(G,st,ord,maxdist,i);
    
    printf("vertice    padre   cammino massimo\n");
    for( j=G->V-1;j>=0;j--){
    
    printf("    %s          %s          %d\n", STsearchByIndex(G->tab,st[j]), STsearchByIndex(G->tab,ord[st[j]]),maxdist[st[j]]);
    }   
    
}
  

        
        free(ord);
        free(maxdist);
        free(st);
    
    
}