#ifndef PG_H
#define PG_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "inv.h"
#define MAXL 200
#define MAXS 50
#define MAXE 8



typedef struct{     //EQUIPAGGIAMENTO tabEquip_t 
    
    inv_t inUso;
    inv_t *vettEq[MAXE];
    
}tabEquip_t ;

typedef struct{            //PERSONAGGIO pg_t
    char codice[6+1];
    char nome[MAXS];
    char classe[MAXS];
    stat_t  stat;
    tabEquip_t  *equip;
    int e, n;
    
    
}pg_t;

typedef struct nodo* link;
typedef struct nodo{        //NODO DELLA LISTA CONTIENE VAL (PERSONAGGIO)  E LINK nodoPg_t
    pg_t personaggio;
    
    link next; 
    
}nodoPg_t;


typedef struct{    //LISTA CON PUNTATORI AI NODI E NUMERO NODI TabPg_t
    
    link head;
    link tail;
    int nPg;
    
}tabPg_t;

typedef tabPg_t * tabPg;

void inserisci_lista(tabPg listap, pg_t pers);
void elimina_personaggio(tabPg listap);
void libera_nodo(link x);
void aggiungi_personaggio(tabPg listap, tabInv invp,char *file);
void libera_lista(tabPg listap);
void stampa_personaggio(link x);
void stampa_personaggi(tabPg listap);
pg_t leggi_personaggio(FILE *f);
void carica_personaggi(tabPg listap,tabInv invp);
int  conta_personaggi(tabPg listap,FILE * f);
link new_node(pg_t val , link next);

void set_inUso(link target);
int check_equip(link x);
void componi_equip(tabPg listap, tabInv invp);
void aggiorna_stat(link target, inv_t oggetto,int k);
void stampa_equipaggiamento(link x);
link ricerca_codice(tabPg listap,char* scelta,link *prev);




#endif