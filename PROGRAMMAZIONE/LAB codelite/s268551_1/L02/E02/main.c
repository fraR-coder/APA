#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAXR 1000 // numero massimo righe file
#define MAXS 31  // dimensione max stringhe


typedef enum{
    
r_date,r_partenza,r_capolinea, r_ritardo, r_ritardo_tot, r_fine
    
} comando_e;

typedef struct{
    char ora_arrivo[MAXS];
    char ora_partenza[MAXS];
    int ritardo;
    char  data[MAXS];
    char partenza[MAXS];
    char destinazione[MAXS];
    char codice[MAXS];
    
    
} Elenco;

typedef struct{
    int anno;
    int mese;
    int giorno;
    
    
}Date;

void stampa(Elenco corsa[], int indice[],int dim);
void stampa_ritardo(Elenco corsa[], int indice[],int dim);
int confronta_date(int dim,Date dat[],int indice[],Date date_input[]);
void seleziona_dati (Elenco corsa[], int dim , comando_e c,Date dat[],Date date_input[]);
comando_e leggi_comando(char input[][MAXS]);

int main()
{
    int n;
    FILE * fp;
    Elenco corsa[MAXR];
    Date dat[MAXR];
    Date date_input[MAXR];
    int i=0;
    comando_e com;
     char input[6][MAXS] = {"date", "partenza", "capolinea", "ritardo", "ritardo_tot", "fine"};
    
    fp=fopen("log.txt","r");
    if(fp==NULL){
        exit(1);
    }
    
    fscanf(fp,"%d",&n);
    
    for(i=0;i<n;i++){
        fscanf(fp,"%s%s%s%s%s%s%d",corsa[i].codice,corsa[i].partenza,corsa[i].destinazione,corsa[i].data,corsa[i].ora_partenza,corsa[i].ora_arrivo,&corsa[i].ritardo);
    }
    
    for(i=0;i<n;i++){
     sscanf(corsa[i].data,"%d/%d/%d",&dat[i].anno,&dat[i].mese,&dat[i].giorno);   
    }
    
    fclose(fp);
    
    
    do{
    com=leggi_comando(input);
    if(com==5){
        printf("finito");
        exit(2);
        }
      
      seleziona_dati(corsa,n,com,dat,date_input);
      
      
      
      
      
    
    }while(com!=5);
      
        
    
    
	return 0;
}


void stampa(Elenco corsa[], int indice[],int dim){
    for(int i=0;i<dim;i++){
printf("%s %s %s %s %s %s %d\n",corsa[indice[i]].codice,corsa[indice[i]].partenza,corsa[indice[i]].destinazione,corsa[indice[i]].data,corsa[indice[i]].ora_partenza,corsa[indice[i]].ora_arrivo,corsa[indice[i]].ritardo);
    }


 for(int i=0;i<dim;i++){
        indice[i]=0;
    }
}

void stampa_ritardo(Elenco corsa[], int indice[],int dim){
    for(int i=0;i<dim;i++){
        if(corsa[indice[i]].ritardo!=0){
printf("%s %s %s %s %s %s %d\n",corsa[indice[i]].codice,corsa[indice[i]].partenza,corsa[indice[i]].destinazione,corsa[indice[i]].data,corsa[indice[i]].ora_partenza,corsa[indice[i]].ora_arrivo,corsa[indice[i]].ritardo);
    }

    }
 for(int i=0;i<dim;i++){
        indice[i]=0;
    }
}
comando_e leggi_comando( char input[][MAXS]){
    
    char scelta[MAXS];
    
    int i=0;
    

    printf("scegli un comando tra date partenza capolinea ritardo ritardo_tot fine\n");
    
    scanf("%s",scelta);
    
  for (i=0; i<6; i++) {
	if (strcmp(scelta, input[i]) == 0){
      return (comando_e) i;
    }
    }
    
    printf("non  hai inserito un comando corretto\n");
    return -1;

   
}




int  confronta_date(int dim,Date dat[],int indice[],Date date_input[]){

    
    int i;
    int j=0;
    
    for( i=0;i<dim;i++){
            
                  if(date_input[0].anno>date_input[1].anno){
                       if(dat[i].anno<= date_input[0].anno && dat[i].anno>= date_input[1].anno){
                             indice[j]=i;
                             j++;
                       }
                    }
                else   if(date_input[0].anno<date_input[1].anno){
                    if(dat[i].anno<=date_input[1].anno && dat[i].anno>= date_input[0].anno){
                             indice[j]=i;
                             j++;
                       }
                    }
                else  {
            
                        if(date_input[0].mese>date_input[1].mese){
                            
                             if(dat[i].mese<= date_input[0].mese && dat[i].mese>= date_input[1].mese){
                                    indice[j]=i;
                                    j++;
                             }
                        }
                            else  if(date_input[0].mese<date_input[1].mese){
                                if(dat[i].mese<= date_input[1].mese && dat[i].mese>= date_input[0].mese){
                                    indice[j]=i;
                                    j++;
                                }
                            }
                          else  {
                               if(date_input[0].giorno>date_input[1].giorno){
                                    if(dat[i].giorno<= date_input[0].giorno && dat[i].giorno>= date_input[1].giorno){
                                    indice[j]=i;
                                    j++;
                                }
                                }
                                else  if(date_input[0].giorno<date_input[1].giorno){
                                     if(dat[i].giorno<=date_input[1].giorno && dat[i].giorno>= date_input[0].giorno){
                                    indice[j]=i;
                                    j++;
                                }
                                }
                                
                                else{
                                   
                                     return 0;
                                
                                }
                          }
                }   
                          
                                 
    }
                
         
    return j;
      

}

void seleziona_dati(Elenco corsa[], int dim, comando_e c,Date dat[],Date date_input[] ){
    
    int i,x,j;
   
    char stazione[MAXS];
    char codice[MAXS];
    int indice[dim];
   
    
    switch(c){
        case r_date: 
        i=0;
        printf("dimmi la  prima data [aaaa/mm/gg]:\n ");
        scanf("%d%d%d",&date_input[i].anno,&date_input[i].mese,&date_input[i].giorno);
        i++;
        printf("dimmi la  seconda data [aaaa/mm/gg]:\n ");
        scanf("%d%d%d",&date_input[i].anno,&date_input[i].mese,&date_input[i].giorno);
        
        x=confronta_date(dim,dat,indice,date_input);
        
        if(x!=0){
                stampa(corsa,indice,x);
        }
        else{
              printf("non trovate\n");
        }
        break;
        
        case r_partenza: 
        printf("fermata partenza?\n");
        scanf("%s",stazione);
        j=0;
        for(i=0;i<dim;i++){
            if(strcmp(stazione,corsa[i].partenza)==0){
                indice[j]=i;
                j++;
            }
        }
        stampa(corsa,indice,j);
        break;
        
        case r_capolinea:
          printf("fermata capolinea?\n");
        scanf("%s",stazione);
        j=0;
        for(i=0;i<dim;i++){
            if(strcmp(stazione,corsa[i].destinazione)==0){
                indice[j]=i;
                j++;
            }
        }
        stampa(corsa,indice,j);
        break;
        
        case r_ritardo:
          i=0;
        printf("dimmi la  prima data [aaaa/mm/gg]:\n ");
        scanf("%d%d%d",&date_input[i].anno,&date_input[i].mese,&date_input[i].giorno);
        i++;
        printf("dimmi la  seconda data [aaaa/mm/gg]:\n ");
        scanf("%d%d%d",&date_input[i].anno,&date_input[i].mese,&date_input[i].giorno);
        
        x=confronta_date(dim,dat,indice,date_input);
        
        if(x!=0){
                stampa_ritardo(corsa,indice,x);
        }
        else{
              printf("non trovate\n");
        }
        break;
        
        case r_ritardo_tot:
        printf("dimmi il codice\n");
        scanf("%s",codice);
        j=0;
         for(i=0;i<dim;i++){
             if(strcmp(codice,corsa[i].codice)==0){
                 
                j+= corsa[i].ritardo;
             }
                
        }
        printf("il ritardo totale e %d\n",j);
        break;
        
        default:
        printf("problema\n");
        break;
        
        
                        
    }
}
    
