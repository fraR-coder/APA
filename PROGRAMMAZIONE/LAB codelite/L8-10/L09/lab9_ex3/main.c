#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "inv.h"
#include "pg.h"

int main()
{
	 tabPg listap=malloc(sizeof(tabPg_t));
    tabInv invp=malloc(sizeof(tabInv_t));
    int scelta;
    char file[MAXS];
   link test,p;
    char t[MAXS];
    
    carica_inventario(invp);
   carica_personaggi(listap,invp);
    
do{
    printf("MENU\nstampa elenco personaggi-1\nstampa inventario-2\naggiungi/rimuovi oggetto-3\naggiungi personaggio-4\nelimina personaggio-5\nstampa personaggio con il suo equipaggiamento-6\ntermina-0\n");
    scanf("%d",&scelta);
    
    switch(scelta){
        case 0:
            printf("finito!\n");
            break;
     
        case 1:
            stampa_personaggi(listap);         
            break;
            
        case 2:
          stampa_inventario(invp);
            break;
        
        case 3:
               componi_equip( listap, invp);
            break;
            
            case 4:
                    printf("da dove vuoilegerlo?\n");
                    scanf("%s",file);
                    aggiungi_personaggio(listap,invp,file);
                    break;
            case 5:
            elimina_personaggio(listap);
            break;
            case 6:
            printf("codice personagio ");
            scanf("%s",t);
          test=ricerca_codice(listap,t,&p);
           stampa_personaggio(test);
           stampa_equipaggiamento(test);
            break;
        default: 
            printf("non hai inserito un comando corretto\n");
    }
    

}while(scelta!=0);
    
    
    libera_inventario(invp);
    libera_lista(listap); 
    
    
	return 0;
}
