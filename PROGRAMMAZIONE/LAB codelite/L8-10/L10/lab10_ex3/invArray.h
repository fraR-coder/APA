#ifndef INVARRAY_H_DEFINED
#define INVARRAY_H_DEFINED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "inv.h"

/* ADT di prima classe collezione di oggetti di inventario */
typedef struct invArray_s *tabinv  ;

/* creatore e disruttore */
tabinv invArray_init();
void libera_inventario(tabinv invAp);

/* lettura e scrittura su file */
void invArray_read(FILE *fp, tabinv invAp);
void stampa_inventario(FILE *fp, tabinv invAp);
/* stampa un unico oggetto selezionato da indice (nel vettore) */
void invArray_printByIndex(FILE *fp, tabinv invAp, int index);
/* ritorna puntatore a oggetto selezionato da indice (nel vettore) */
inv_t *invArray_getByIndex(tabinv invAp, int index);
/* ritorna indice (nel vettore) a oggetto selezionato da nome */
int invArray_searchByName(tabinv invAp, char *name);

/* Si possono aggiungere altre funzioni se ritenute necessarie */

#endif
