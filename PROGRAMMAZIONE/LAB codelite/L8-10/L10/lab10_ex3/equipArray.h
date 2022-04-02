#ifndef EQUIPARRAY_H_DEFINED
#define EQUIPARRAY_H_DEFINED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define EQUIP_SLOT 8

#include "invArray.h"

/* ADT di prima classe collezione di oggetti di equipaggiamento */
typedef struct equipArray_s *equipArray_t; 

/* creatore e disruttore */
equipArray_t equipArray_init();
void equipArray_free(equipArray_t eqAp);

/* quanti equipaggiamenti sono in uso */
int equipArray_inUse(equipArray_t eqAp);

/* scrittura su file */
void equipArray_print(FILE *fp, equipArray_t eqAp, tabinv invp);
/* modifica equipaggiamento scegliendo un oggetto da inventario */
void equipArray_update(equipArray_t eqAp, tabinv invp);
/* torna indice (nel vettore inventario) dell'oggetto in posizione index (0..EQUIP_SLOT-1) di equipArray */
int equipArray_getEquipByIndex(equipArray_t eqAp, int index);

/* Si possono aggiungere altre funzioni se ritenute necessarie */

#endif
