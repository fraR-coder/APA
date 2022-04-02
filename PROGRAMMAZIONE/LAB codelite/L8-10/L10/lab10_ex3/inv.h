#ifndef INV_H_DEFINED
#define INV_H_DEFINED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LEN 100
#define MIN_STAT 1

/* quasi ADT statistiche */
typedef struct stat_s {
  int hp, mp, atk, def, mag, spr;
} stat_t;

/* quasi ADT oggetto di inventario */
typedef struct inv_s {
  char nome[LEN];
  char tipo[LEN];
  stat_t stat;
} inv_t;

/* funzioni di input/output delle statistiche */
void leggi_stat(FILE *fp, stat_t *statp);
void stampa_stat(FILE *f ,stat_t *tmp,int min);

/* funzioni di input/output di un oggetto dell'inventario */
void leggi_oggetto(FILE *fi, inv_t *invp);
void stampa_oggetto(FILE *fp, inv_t *invp);

/* ritorna il campo stat di un oggetto dell'inventario */
stat_t get_stat(inv_t *invp);

/* Si possono aggiungere altre funzioni se ritenute necessarie */

stat_t  aggiorna_stat(stat_t b, stat_t e);
#endif
