#ifndef Quotazioni_H
#define Quotazioni_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "data.h"

typedef struct  binarysearchtree *BST;

typedef struct quotazionegiornaliera{
    
 
    float quotazione;
    float  num,den;
    
}quot_s;

BST  BSTinit(int N);
void BSTfree(BST bst);
float BSTsearchByDate(BST Q,data_s data);
void  BSTinsert(BST Q,data_s data,int n,int val,float * quotazione);
void BSTprint(BST Q,FILE* fout);
void BSTsearchMaxMin(BST Q,data_s d1,data_s d2,float* max,float* min);

void BSTbalance(BST Q,int S);



#endif