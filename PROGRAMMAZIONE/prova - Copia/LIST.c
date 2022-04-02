#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LIST.h"

typedef struct node{
    int val;
    struct node *next;
    struct node *prev;
}*link;

 struct list{
    link r;
};

static link node_new(int val,link prev,link next){
    link x;
    x=calloc(1,sizeof(*x));
    x->val=val;
    x->prev=prev;
    x->next=next;
    if(x->prev!=NULL)
        x->prev->next=x;
    if(x->next!=NULL)
        x->next->prev=x;
    return x;
}
void node_free(link nd){
    free(nd);
}


LIST list_init( void ){
    return calloc(1,sizeof(LIST));
}

static link list_freeHeadP(LIST l){
    link x;
    if(NULL!=l->r)
    {
        x=l->r;
        l->r=l->r->next;
        node_free(x);
    }
    return l->r;
}
static void list_clean(LIST l){
    while(NULL!=list_freeHeadP(l));
}
void list_free(LIST l){
    if(NULL!=l)
    {
        list_clean(l);
        free(l);
    }
    l=NULL;
}
void list_insHeadP( LIST l, int  val){
    l->r=node_new(val,NULL,l->r);
}
void list_print(LIST l){
    link x;
    link h=l->r;
    if(h!=NULL){
        printf("%d",h->val);
        for(x=h->next;x!=NULL;x=x->next)
            printf( " <-> %d",x->val);
    }
}

void purge(LIST l, int div){
    link h=l->r;
    link x;
    while(h!=NULL){
        x=h->next;
        if(h->val%div!=0){
            if(h->prev==NULL){
                h=h->next;
                h->prev=NULL;
                l->r=h;
            }
            else if(h->next==NULL){
                h->prev->next=NULL;
            }
            else {
                h->prev->next=h->next;
                h->next->prev=h->prev;
            }
        }
        h=x;
//      if(h==NULL) break;
    }
}