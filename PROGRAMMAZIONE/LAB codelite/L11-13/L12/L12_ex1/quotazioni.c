#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "quotazioni.h"


typedef struct BSTnode* link;

struct BSTnode { data_s day;quot_s qg; link l; link  r; int N;};


struct binarysearchtree { link root; int N;};


BST BSTinit( int N) {
  BST bst = malloc(N*sizeof (*bst)) ;
  bst->N=N;
  bst->root=NULL;
  return bst;
}
static void treeFree(link h) {
  if (h == NULL)
    return;
  treeFree(h->l);
  treeFree(h->r);
  free(h);
}
void BSTfree(BST bst) {
  if (bst == NULL)
    return;
  treeFree(bst->root);

  free(bst);
}




static link  calcola_quotazione(link x,float val,float n){
    
  
        float num=x->qg.num+=val*n;
        float den=x->qg.den+=n;
        
        x->qg.quotazione=num/den;

    
    return x ;
}

static link NEW(data_s day, int val,int n,link l, link r) {
  link x = malloc(sizeof *x);
  x->day=day;
  x->qg.den=0;
  x->qg.num=0;
  x->N=1;
  x=calcola_quotazione(x,val,n);
 
  x->l = l;
  x->r = r; 

  return x;
}
static link  BSTsearchByDateR(link h,data_s data){
      int cmp;
  if (h == NULL)
    return NULL;
  cmp = compara_date(data, h->day);
  if (cmp==0)
    return h;
  if (cmp==-1)
    return BSTsearchByDateR(h->l, data);
  else
    return BSTsearchByDateR(h->r, data);
    
    
}


float  BSTsearchByDate(BST Q,data_s data){
    
    link x= BSTsearchByDateR(Q->root,data);
    
    return x->qg.quotazione;
    
}

static link BSTinsertR(link h,data_s data,int n,int val,float* quotazione){
      int cmp;
  link x;
  if (h == NULL) {
    x = NEW(data, val, n, NULL, NULL);
    *quotazione=x->qg.quotazione;
    return x;
  }
  cmp =compara_date(data,h->day);
  if (cmp < 0) {
    h->l = BSTinsertR(h->l, data, val, n,quotazione);
  } else if (cmp > 0) {
    h->r = BSTinsertR(h->r, data, val, n,quotazione);
  } else {
    h->qg.num += n * val;
    h->qg.den += n;
    
  }
  
  h->N++;
return h;    
}

void  BSTinsert(BST Q,data_s data,int n,int val,float *quotazione){
    
    
    Q->root=BSTinsertR(Q->root,data,n,val,quotazione);
    
}

static void stampa_quotazione(quot_s q,FILE *fout){
    fprintf(fout,"%.1f\n",q.quotazione);
    
}


void BSTprintR(link h,FILE* fout){
      if (h == NULL)
    return;

  BSTprintR(h->l, fout);
  stampa_data(fout,h->day);
  stampa_quotazione(h->qg,fout);
 BSTprintR(h->r, fout);
}
    

void BSTprint(BST Q,FILE* fout){
    
    BSTprintR(Q->root,fout);
    
}

void BSTsearchMaxMinR(link h,data_s d1,data_s d2,float* max,float* min){
    
    int cmp1,cmp2;
    if(h==NULL) return;
    
    cmp1=compara_date(d1,h->day);
    cmp2=compara_date(d2,h->day);
    
    if(cmp1<=0 && cmp2>=0){
        if(h->qg.quotazione>*max) *max=h->qg.quotazione;
        if(h->qg.quotazione<*min) *min=h->qg.quotazione;
      
    }
    
    if(cmp1<0){
        BSTsearchMaxMinR(h->l,d1,d2,max,min);
       
    }
    if(cmp2>0){
        BSTsearchMaxMinR(h->r,d1,d2,max,min);
    }
 
}

void BSTsearchMaxMin(BST Q,data_s d1,data_s d2,float* max,float* min){
    
    
    BSTsearchMaxMinR(Q->root,d1,d2,max,min);
    
}

static void findCamminoMaxMin(link r,int * min,int *max,int pos){
    
    if(r==NULL) return;
    
     
    if(r->l==NULL && r->r==NULL){ //sono in una foglia
        if(pos>*max){
            *max=pos;
        }
        if(pos<*min){
            *min=pos;
        }
        return;
    }
    

    findCamminoMaxMin(r->l,min,max,pos+1);
    
    findCamminoMaxMin(r->r,min,max,pos+1);
    
  
    
    return;
    
}

link rotR(link h) {
  link x = h->l;
  h->l = x->r;
  x->r = h;
  x->N = h->N;
  h->N = 1;
  h->N += (h->l) ? h->l->N : 0;
  h->N += (h->r) ? h->r->N : 0;
  return x;
}

link rotL(link h) {
  link x = h->r;
  h->r = x->l;
  x->l = h;
  x->N = h->N;
  h->N = 1;
  h->N += (h->l) ? h->l->N : 0;
  h->N += (h->r) ? h->r->N : 0;
  return x;
}

static link treePartition(link h, int k) {
 int t ;
 if(h->l !=NULL){
    t = h->l->N;
 }
 else t=0;
 
 if (h == NULL)
    return NULL;
 
  if (t > k) {
    h->l = treePartition(h->l, k);
    h = rotR(h);
  }
  if (t < k) {
    h->r = treePartition(h->r, k-t-1);
    h = rotL(h);
  }
  return h;
}

static link bilanciaR(link h) {
     int k;
  if (h == NULL)
    return NULL;
  k = (h->N+1)/2-1;
  h = treePartition(h, k);
  h->l = bilanciaR(h->l);
  h->r = bilanciaR(h->r);
  return h;
    
}

static void bilancia(BST Q){
    
    Q->root = bilanciaR(Q->root);
}


void BSTbalance(BST Q,int S){
    int max=0;
    int min=INT_MAX;
    int pos=0;
    int s;
    findCamminoMaxMin(Q->root,&min,&max,pos);
    
    s=max/min;
    if(s>S){
        bilancia(Q);
        max=0;
        min=INT_MAX;
        findCamminoMaxMin(Q->root,&min,&max,pos);
    }
    
        printf("max %d min %d\n",max,min);
}
