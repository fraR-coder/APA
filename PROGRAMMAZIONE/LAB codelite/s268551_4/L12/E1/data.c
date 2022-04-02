#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "data.h"

int compara_date(data_s d1,data_s d2){
    
    if(d1.a>d2.a)  return 1;
    if(d1.a==d2.a){
        if(d1.m>d2.m) return 1;
        if(d1.m==d2.m){
            if(d1.g>d2.g) return 1;
            if(d1.g==d2.g) {
                return 0;
                
            }
        }
    }
    
    return -1;
    
    
}

data_s leggi_data(FILE* fin){

    data_s d;
    
        fscanf(fin,"%d/%d/%d %d:%d",&d.a,&d.m,&d.g,&d.ora.h,&d.ora.m);
   
    return d;
}


void stampa_data(FILE *fout,data_s d){
    fprintf(fout,"%d/%d/%d %d:%d  ",d.a,d.m,d.g,d.ora.h,d.ora.m);
    
}