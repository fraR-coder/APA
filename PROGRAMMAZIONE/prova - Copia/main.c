#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "LIST.h"

int main(int argc,char **argv)
{
    int ix;
    int div=3;
    LIST l;

    l=list_init();
    for(ix=0;ix<10;ix++)
        list_insHeadP(l,ix);
    printf("div = %d",div);
    list_insHeadP(l,14);
    printf("Stampa lista input \n");
    list_print(l);

    purge(l,div);

    printf("\nStampa lista output\n");
    list_print(l);
    list_free(l);
    return 0;
}
