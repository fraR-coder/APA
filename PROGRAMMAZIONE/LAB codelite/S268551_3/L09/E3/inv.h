#ifndef INV_H
#define INV_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAXL 200
#define MAXS 50
#define MAXE 8

typedef struct{          //STATISTICHE  Stat_t;
    int hp;
    int mp;
    int atk;
    int def;
    int mag;
    int spr;
    
}stat_t;


typedef struct{    //INVENTARIO inv_t
    char nome[MAXS];
    char tipo[MAXS];
    stat_t stat;
    
}inv_t;


typedef struct{           //INVENTARIO WRAPPER tabInv_t
    int nInv;
    
    inv_t  *vettInv;
    
}tabInv_t;
typedef tabInv_t  *tabInv;




void stampa_inventario(tabInv invp);
void stampa_oggetto(inv_t oggetto);
void stampa_stat(stat_t stat,int min);
void libera_inventario(tabInv invp);
void carica_inventario(tabInv invp);
stat_t leggi_stat(FILE *f);

#endif
