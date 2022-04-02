#ifndef Data_H
#define Data_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct{
    int h,m;    
}giorno;

typedef struct {
    int a,m,g;
    giorno ora;
}data_s;

int compara_date(data_s d1,data_s d2);
data_s leggi_data(FILE*fin);
void stampa_data(FILE *fout,data_s d);




#endif