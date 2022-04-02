#include <stdio.h>
#include <stdlib.h>

#define MAXS 20

#include "data.h"
#include "titoli.h"
#include "quotazioni.h"


void stampa_menu(FILE *fp){
    
    printf("MENU\nACQUISISCI FILE-1\nCERCA TITOLO-2\nTROVA QUOTAZIONE-3\nCERCA MIN,MAX-4\nCERCA MAX,MIN TOTALE\nBILANCIA ALBERO-6\nFINE-0\n");
    
}

int main(int argc, char **argv)
{
    int scelta;
     int S;
    char codice[MAXS];
    data_s data,data1;
    LIST LT=LISTinit();
    NODE x;
    NODE p;
    FILE *fin;
    do{
        stampa_menu(stdout);
        scanf("%d",&scelta);
        switch (scelta){
            case 0: break;
            case 1:
                fin=fopen("F1.txt","r");
                leggi_file(LT,fin);
                stampa_lista(LT,stdout);
                break;
            case 2:
                printf("inserisci titolo\n");
                scanf("%s",codice);
                x=  LISTsearch_by_code(LT,&p,codice);
                if(x!=NULL) printf("trovato\n");
                
                break;
            case 3:
                printf("inserisci data aaaa/mm/gg\n");
                data=leggi_data(stdin);
                printf("%f\n",cerca_quotazione(x,data));
                break;
                
                case 4:
                printf("inserisci data aaaa/mm/gg\n");
                data=leggi_data(stdin);
                printf("inserisci data aaaa/mm/gg\n");
                data1=leggi_data(stdin);
                cercaMaxMin(data,data1,x);
                break;
                
                case 5: 
                printf("MAX %f, MIN %f\n",getMAX(x),getMIN(x));
                break;
                
                case 6:
                printf("soglia\n");
                scanf("%d",&S);
                    bilanciamento(x,S);
                    break;
                    
                default : break;
        }
        
        
    }while(scelta!=0);
    
   
 
    
  
    
  
    
    
    
	LISTfree(LT);
    
	return 0;
}
