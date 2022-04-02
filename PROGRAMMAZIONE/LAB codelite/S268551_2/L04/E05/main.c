#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAXR 1000 // numero massimo righe file
#define MAXS 31  // dimensione max stringhe



typedef enum{
    
stampa_per_data,stampa_per_codice,stampa_per_stazionep,stampa_per_stazionea,ricerca,fine
    
} comando;
typedef struct {
    int ora;
    int minuto;
    int secondi;
    
    
}Date2;

typedef struct {
    int anno;
    int mese;
    int giorno;
    
    
}Date1;
typedef struct{
    Date2  orariop,orarioa;
    char ora_arrivo[MAXS];
    char ora_partenza[MAXS];
    int ritardo;
   Date1 dat;
   char data[MAXS];
    char partenza[MAXS];
    char destinazione[MAXS];
    char codice[MAXS];
    
    
} Elenco;



Elenco* CODICE[MAXR],*DATA[MAXR],*PARTENZA[MAXR],*DESTINAZIONE[MAXR];

comando leggi_comando( char *input[]);
int leggi_file(Elenco *corsa);
void stampa(Elenco **corsa,int n);
void stampaf(Elenco **corsa,int n);

void esegui(comando com, Elenco *corsa,int n);
void ordina_d(Elenco **corsa,int n);
void ordina_c(Elenco **corsa,int n);
void ordinasd(Elenco **corsa,int n);
void ordinasp(Elenco **corsa,int n);
int  confronta_date(Elenco *corsa1,Elenco *corsa2, int dim);

void ricercadicotomica(Elenco **corsa, int n);
void cerca_codice(Elenco **corsa, int n);
void cerca_partenza(Elenco **corsa, int n);
void cerca_data(Elenco **corsa, int n);
void cerca_destinazione(Elenco **corsa, int n);
int main()
{
    Elenco corsa[MAXS];
    int n;
  
     comando com;
      char *input[MAXS] = {"stampa_per_data","stampa_per_codice","stampa_per_stazionep","stampa_per_stazionea","ricerca", "fine"};
    

    n=leggi_file(corsa);
    
      do{
    com=leggi_comando(input);
    if(com==5){
        printf("finito");
        exit(2);
        }
      
     esegui(com,corsa,n);
      

    
    }while(com!=5);
    
	
	return 0;
}

int leggi_file( Elenco *corsa){
    
    int n;
    FILE *fp;
   
    fp=fopen("log.txt","r");
    if(fp==NULL){
        exit(1);
    }
    
    fscanf(fp,"%d",&n);
    
      for(int i=0;i<n;i++){
        fscanf(fp,"%s %s %s %s %s %s %d\n",corsa[i].codice,corsa[i].partenza,corsa[i].destinazione,corsa[i].data,corsa[i].ora_partenza,corsa[i].ora_arrivo,&corsa[i].ritardo);
       sscanf(corsa[i].data,"%d/%d/%d",&corsa[i].dat.anno,&corsa[i].dat.mese,&corsa[i].dat.giorno);
       sscanf(corsa[i].ora_partenza,"%d:%d:%d",&corsa[i].orariop.ora,&corsa[i].orariop.minuto,&corsa[i].orariop.secondi);
        sscanf(corsa[i].ora_arrivo,"%d:%d:%d",&corsa[i].orarioa.ora,&corsa[i].orarioa.minuto,&corsa[i].orarioa.secondi);
    }
    for(int i=0;i<n;i++){
    CODICE[i]=&corsa[i];
     DATA[i]=&corsa[i];
      PARTENZA[i]=&corsa[i];
       DESTINAZIONE[i]=&corsa[i];
    }
   
ordina_c(CODICE,n);
ordina_d(DATA,n);
ordinasd(DESTINAZIONE,n);
ordinasp(PARTENZA,n);

    
    return n;
}

comando leggi_comando( char *input[]){
    
    char scelta[MAXS];
    
    int i=0;
   
  printf("\nMENU'\nSeleziona cosa vuoi fare\n");
  for(i=0; i<6; i++) {
    printf("%s\n",input[i]);
  }
  printf("----------------------------\n");
    
    scanf("%s",scelta);
    
  for (i=0; i<6; i++) {
	if (strcmp(scelta, input[i]) == 0){
      return (comando) i;
    }
    }
    
    printf("non  hai inserito un comando corretto\n");
    return -1;

   
}

void esegui(comando com, Elenco *corsa,int n){
    
    switch(com){
       
            
            case stampa_per_data:
          stampa(DATA,n);
         
        
                break;
                
                case stampa_per_codice:
              stampa(CODICE,n);
                
                break;
                
                case stampa_per_stazionep:
                stampa(PARTENZA,n);
                
                break;
                
                case stampa_per_stazionea:
                 stampa(DESTINAZIONE,n);
               
                break;
                
                case ricerca:
                        ricercadicotomica(&corsa,n);
                        break;
         
        
         
    }
    }
    



void stampa(Elenco **corsa,int n){
   int scelta;
    printf("vuoi stampare su file output.txt?\n1-SI\n0-NO\n\n");
    scanf("%d",&scelta);
    
    if(scelta==0){    
    for(int i=0;i<n;i++){
        printf("%s %s %s %s %s %s %d\n",corsa[i]->codice,corsa[i]->partenza,corsa[i]->destinazione,corsa[i]->data,corsa[i]->ora_partenza,corsa[i]->ora_arrivo,corsa[i]->ritardo);
    }
    printf("\n\n");
}

else{
    stampaf(corsa,n);
}
}



void stampaf(Elenco **corsa,int n){
    FILE *fo;
    fo=fopen("output.txt","w");
     for(int i=0;i<n;i++){
        fprintf(fo,"%s %s %s %s %s %s %d\n",corsa[i]->codice,corsa[i]->partenza,corsa[i]->destinazione,corsa[i]->data,corsa[i]->ora_partenza,corsa[i]->ora_arrivo,corsa[i]->ritardo);
    }
    fclose(fo);
    printf("\n\n");
}


int  confronta_date(Elenco *corsa1,Elenco *corsa2, int dim){

    
    int i;
 
    
    for( i=0;i<dim;i++){
            
                  if(corsa1->dat.anno>corsa2->dat.anno){
                      return 1;
                     
                    }
                else if (corsa1->dat.anno==corsa2->dat.anno){
                    
                     if(corsa1->dat.mese>corsa2->dat.mese){
                           return 1;
                }
                    else if (corsa1->dat.mese==corsa2->dat.mese){
                    
                        if(corsa1->dat.giorno>corsa2->dat.giorno){
                           return 1;
                        }
                        
                        else if (corsa1->dat.giorno==corsa2->dat.giorno){
                    
                        if(corsa1->orariop.ora>corsa2->orariop.ora){
                           return 1;
                        }
                        
                       else  if(corsa1->orariop.ora==corsa2->orariop.ora){
                           if(corsa1->orariop.minuto>corsa2->orariop.minuto){
                            return 1;
                           }
                            else  if(corsa1->orariop.minuto==corsa2->orariop.minuto){
                                  if(corsa1->orariop.secondi>corsa2->orariop.secondi){
                            return 1;
                           }
                                            }
                                        }
                                    }
                                }
                        
                            }
                        }
                   
    
                
             
            
       return -1;              

}


void ordina_c(Elenco **corsa,int n){                      //uso bubble sort , stabile
    
  int flag=1;
    Elenco *t;
    
    for(int i=0;i<n-1 && flag==1;i++){
        for(int j=0;j<n-1-i;j++){                                              
            flag=0;
        if(strcmp(corsa[j]->codice,corsa[j+1]->codice)>0){
            
            t=corsa[j];
           
            corsa[j]=corsa[j+1];
           
            corsa[j+1]=t;
            flag=1;
        }
        }
        
    }
    
   
    
}


void ordinasp(Elenco **corsa,int n){
    
     int flag=1;
    Elenco* t;
    
    for(int i=0;i<n-1 && flag==1;i++){
        for(int j=0;j<n-1-i;j++){                                              
            flag=0;
        if(strcmp(corsa[j]->partenza,corsa[j+1]->partenza)>0){
            
            t=corsa[j];
           
            corsa[j]=corsa[j+1];
           
            corsa[j+1]=t;
            flag=1;
        }
        }
        
    }
    
  
    
}


void ordina_d(Elenco **corsa,int n){
    
     int flag=1;
    Elenco *t;
    
    for(int i=0;i<n-1 && flag==1;i++){
        
        flag=0;
        for(int j=0;j<n-1-i;j++){                                              
            
        if(confronta_date(corsa[j],corsa[j+1],n)>0){
            
            t=corsa[j];
           
            corsa[j]=corsa[j+1];
           
            corsa[j+1]=t;
            flag=1;
        }
        
        }
        
        
    }
    
 
    
}
    
    
void ordinasd(Elenco **corsa,int n){
    
     int flag=1;
    Elenco* t;
    
    for(int i=0;i<n-1 && flag==1;i++){
        for(int j=0;j<n-1-i;j++){                                              
            flag=0;
        if(strcmp(corsa[j]->destinazione,corsa[j+1]->destinazione)>0){
            
            t=corsa[j];
           
            corsa[j]=corsa[j+1];
           
            corsa[j+1]=t;
            flag=1;
        }
        }
        
    }
    
   
    
}  


void ricercadicotomica(Elenco **corsa, int n){
    int scelta;
    printf("cosa vuoi cercare\n1-data\n2-codice\n3-stazione partenza\n4-capolinea\n");
    scanf("%d",&scelta);
    
    switch(scelta){
        case 1:
        cerca_data(DATA,n);
        break;
        case 2:
        cerca_codice(CODICE,n);
        break;
        case 3:
        cerca_partenza(PARTENZA,n);
        break;
        case 4:
        cerca_destinazione(DESTINAZIONE,n);
        break;
        
    }
}
  
    
 void cerca_partenza(Elenco ** corsa,int n){
       int m;
   int found=0;
    int pos;
    int i=0;
    int f=n-1;
    char x[MAXS];
    int l=0;
   
  
    printf("dimmi il nome della stazione di parteza\n");
    scanf("%s",x);
    l=strlen(x);
    
    
   while(i<=f && !found){
        m=(i+f)/2;
        if(strncmp(x,corsa[m]->partenza,l)>0){
            i=m+1;
        }
        else if(strncmp(x,corsa[m]->partenza,l)<0){
            f=m-1;
        }
        else   {
         printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
         pos=m;
         m++;
        while(m<n && (strncmp(x,corsa[m]->partenza,l)==0)){
             printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
             m++;
        }
        pos--;
        m=pos;
       while(m>=0 && (strncmp(x,corsa[m]->partenza,l)==0)){
        printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
             m--;
        }
        
        found=1;
        
        }
        
       
}
 if(found==0){
            printf("non trovato\n");
        }
}

void cerca_codice(Elenco **corsa, int n){
    int m;
   int found=0;
    int pos;
    int i=0;
    int f=n-1;
    char x[MAXS];
    int l=0;
   
    
    printf("dimmi il codice\n");
    scanf("%s",x);
    l=strlen(x);
    
    
    while(i<=f && !found){
        m=(i+f)/2;
        if(strncmp(x,corsa[m]->codice,l)>0){
            i=m+1;
        }
        else if(strncmp(x,corsa[m]->codice,l)<0){
            f=m-1;
        }
        else   {
        printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
         pos=m;
         m++;
        while(m<n && (strncmp(x,corsa[m]->codice,l)==0) ){
             printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
             m++;
        }
        pos--;
        m=pos;
       while(m>=0 && (strncmp(x,corsa[m]->codice,l)==0)){
           printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
             m--;
        }
        
        found=1;
        
        }
        
       
}
 if(found==0){
            printf("non trovato\n");
        }
}

void cerca_destinazione(Elenco **corsa, int n){
    int m;
   int found=0;
    int pos;
    int i=0;
    int f=n-1;
    char x[MAXS];
    int l=0;
   
  
    printf("dimmi il nome della stazione di arrivo\n");
    scanf("%s",x);
    l=strlen(x);
    
    
    while(i<=f && !found){
        m=(i+f)/2;
        if(strncmp(x,corsa[m]->destinazione,l)>0){
            i=m+1;
        }
        else if(strncmp(x,corsa[m]->destinazione,l)<0){
            f=m-1;
        }
         else   {
        printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
         pos=m;
         m++;
        while(m<n && (strncmp(x,corsa[m]->destinazione,l)==0)){
             printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
             m++;
        }
        pos--;
        m=pos;
       while(m>=0 && (strncmp(x,corsa[m]->destinazione,l)==0)){
           printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
             m--;
        }
        found=1;
        
        }
        
       
}
 if(found==0){
            printf("non trovato\n");
        }
}
    
    
void cerca_data(Elenco **corsa, int n){
    int m;
   int found=0;
    int pos;
    int i=0;
    int f=n-1;
    char x[MAXS];
    int l=0;
   
  
    printf("dimmi la data\n");
    scanf("%s",x);
    l=strlen(x);
    
    
    while(i<=f && !found){
        m=(i+f)/2;
        if(strncmp(x,corsa[m]->data,l)>0){
            i=m+1;
        }
        else if(strncmp(x,corsa[m]->data,l)<0){
            f=m-1;
        }
          else   {
        printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
         pos=m;
         m++;
        while(m<n && (strncmp(x,corsa[m]->data,l)==0)){
             printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
             m++;
        }
        pos--;
        m=pos;
       while(m>=0 && (strncmp(x,corsa[m]->data,l)==0)){
           printf("%s %s %s %s %s %s %d\n",corsa[m]->codice,corsa[m]->partenza,corsa[m]->destinazione,corsa[m]->data,corsa[m]->ora_partenza,corsa[m]->ora_arrivo,corsa[m]->ritardo);
             m--;
        }
        
        found=1;
        
        }
        
       
}
 if(found==0){
            printf("non trovato\n");
        }
}
    

