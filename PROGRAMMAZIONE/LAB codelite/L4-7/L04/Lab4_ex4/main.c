#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAXR 1000 // numero massimo righe file
#define MAXS 31  // dimensione max stringhe

int ordinato=0;

typedef enum{
    
stampa_video,stampa_su_file,ordina_data,ordina_codice,ordina_stazionep,ordina_stazionea,ricerca,fine
    
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


comando leggi_comando( char *input[]);
int leggi_file(Elenco *corsa);
void stampa(Elenco *corsa,int n);
void stampaf(Elenco *corsa,int n);
void esegui(comando com, Elenco *corsa,int n);
void ordina_d(Elenco *corsa,int n);
void ordina_c(Elenco *corsa,int n);
void ordinasd(Elenco *corsa,int n);
void ordinasp(Elenco *corsa,int n);
int  confronta_date(Elenco corsa1,Elenco corsa2, int dim);
void cerca(Elenco *corsa,int n);
void ricercadicotomica(Elenco *corsa, int n, int l, char *x);
int main()
{
    Elenco corsa[MAXS];
    int n;
  
     comando com;
      char *input[MAXS] = {"stampa_video","stampa_su_file","ordina_data","ordina_codice","ordina_stazionep","ordina_stazionea","ricerca", "fine"};
    

    n=leggi_file(corsa);
    
      do{
    com=leggi_comando(input);
    if(com==7){
        printf("finito");
        exit(2);
        }
      
      esegui(com,corsa,n);
      

    
    }while(com!=7);
    
	
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
    
    return n;
}

comando leggi_comando( char *input[]){
    
    char scelta[MAXS];
    
    int i=0;
   
  printf("\nMENU'\nSeleziona cosa vuoi fare\n");
  for(i=0; i<8; i++) {
    printf("%s\n",input[i]);
  }
  printf("----------------------------\n");
    
    scanf("%s",scelta);
    
  for (i=0; i<8; i++) {
	if (strcmp(scelta, input[i]) == 0){
      return (comando) i;
    }
    }
    
    printf("non  hai inserito un comando corretto\n");
    return -1;

   
}

void esegui(comando com, Elenco *corsa,int n){
    
    switch(com){
        case stampa_video:
            stampa(corsa,n);
            ordinato=0;
            break;
            
            case stampa_su_file:
            stampaf(corsa,n);
            ordinato=0;
            break;
            
            case ordina_data:
          ordina_d(corsa,n);
          ordinato=0;
                break;
                
                case ordina_codice:
                ordina_c(corsa,n);
                ordinato=0;
                break;
                
                case ordina_stazionep:
                ordinasp(corsa,n);
               ordinato=1;
                
                break;
                
                case ordina_stazionea:
                ordinasd(corsa,n);
              ordinato=0;
                break;
                
                case ricerca:
                        cerca(corsa,n);
                        break;
         
    }
    }
    



void stampa(Elenco *corsa,int n){
    for(int i=0;i<n;i++){
        printf("%s %s %s %s %s %s %d\n",corsa[i].codice,corsa[i].partenza,corsa[i].destinazione,corsa[i].data,corsa[i].ora_partenza,corsa[i].ora_arrivo,corsa[i].ritardo);
    }
    printf("\n\n");
}

void stampaf(Elenco *corsa,int n){
    FILE *fo;
    fo=fopen("output.txt","w");
     for(int i=0;i<n;i++){
        fprintf(fo,"%s %s %s %s %s %s %d\n",corsa[i].codice,corsa[i].partenza,corsa[i].destinazione,corsa[i].data,corsa[i].ora_partenza,corsa[i].ora_arrivo,corsa[i].ritardo);
    }
    fclose(fo);
    printf("\n\n");
}

void ordina_c(Elenco *corsa,int n){                      //uso bubble sort , stabile
    
  int flag=1;
    Elenco t;
    
    for(int i=0;i<n-1 && flag==1;i++){
        for(int j=0;j<n-1-i;j++){                                              
            flag=0;
        if(strcmp(corsa[j].codice,corsa[j+1].codice)>0){
            
            t=corsa[j];
           
            corsa[j]=corsa[j+1];
           
            corsa[j+1]=t;
            flag=1;
        }
        }
        
    }
    
    stampa(corsa,n);
    
}

void ordinasp(Elenco *corsa,int n){
    
     int flag=1;
    Elenco t;
    
    for(int i=0;i<n-1 && flag==1;i++){
        for(int j=0;j<n-1-i;j++){                                              
            flag=0;
        if(strcmp(corsa[j].partenza,corsa[j+1].partenza)>0){
            
            t=corsa[j];
           
            corsa[j]=corsa[j+1];
           
            corsa[j+1]=t;
            flag=1;
        }
        }
        
    }
    
    stampa(corsa,n);
    
}

void ordinasd(Elenco *corsa,int n){
    
     int flag=1;
    Elenco t;
    
    for(int i=0;i<n-1 && flag==1;i++){
        for(int j=0;j<n-1-i;j++){                                              
            flag=0;
        if(strcmp(corsa[j].destinazione,corsa[j+1].destinazione)>0){
            
            t=corsa[j];
           
            corsa[j]=corsa[j+1];
           
            corsa[j+1]=t;
            flag=1;
        }
        }
        
    }
    
    stampa(corsa,n);
    
}

void ordina_d(Elenco *corsa,int n){
    
     int flag=1;
    Elenco t;
    
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
    
    stampa(corsa,n);
    
}
    
int  confronta_date(Elenco corsa1,Elenco corsa2, int dim){

    
    int i;
 
    
    for( i=0;i<dim;i++){
            
                  if(corsa1.dat.anno>corsa2.dat.anno){
                      return 1;
                     
                    }
                else if (corsa1.dat.anno==corsa2.dat.anno){
                    
                     if(corsa1.dat.mese>corsa2.dat.mese){
                           return 1;
                }
                    else if (corsa1.dat.mese==corsa2.dat.mese){
                    
                        if(corsa1.dat.giorno>corsa2.dat.giorno){
                           return 1;
                        }
                        
                        else if (corsa1.dat.giorno==corsa2.dat.giorno){
                    
                        if(corsa1.orariop.ora>corsa2.orariop.ora){
                           return 1;
                        }
                        
                       else  if(corsa1.orariop.ora==corsa2.orariop.ora){
                           if(corsa1.orariop.minuto>corsa2.orariop.minuto){
                            return 1;
                           }
                            else  if(corsa1.orariop.minuto==corsa2.orariop.minuto){
                                  if(corsa1.orariop.secondi>corsa2.orariop.secondi){
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


void cerca(Elenco *corsa,int n){
    char x[MAXS];
    int l=0;
    int k=0;
    printf("dimmi il nome della stazione di parteza\n");
    scanf("%s",x);
    l=strlen(x);
    int ok;
    int found=0;
    
    if(ordinato==0){
        for(int j=0;j<n;j++){
            if(x[0]==corsa[j].partenza[0]){
                ok=1;
                
                for(k=0;k<l && ok==1;k++){
                    
                    if(x[k]!=corsa[j].partenza[k]){
                        ok=0;
                }
               
                }
                 if(ok){
                    printf("%s %s %s %s %s %s %d\n",corsa[j].codice,corsa[j].partenza,corsa[j].destinazione,corsa[j].data,corsa[j].ora_partenza,corsa[j].ora_arrivo,corsa[j].ritardo);
                    found=1;
                }
                
            }
       }
       if(found==0){
           printf("non trovato\n");
       }
    }
    else{
        ricercadicotomica(corsa,n,l,x);
    }
    
  
    
    
 
}

void ricercadicotomica(Elenco *corsa, int n, int l, char *x){
    int m;
   int found=0;
    int pos;
    int i=0;
    int f=n-1;
    
    
    while(i<=f && !found){
        m=(i+f)/2;
        if(strncmp(x,corsa[m].partenza,l)>0){
            i=m+1;
        }
        else if(strncmp(x,corsa[m].partenza,l)<0){
            f=m-1;
        }
        else   {
         printf("%s %s %s %s %s %s %d\n",corsa[m].codice,corsa[m].partenza,corsa[m].destinazione,corsa[m].data,corsa[m].ora_partenza,corsa[m].ora_arrivo,corsa[m].ritardo);
         pos=m;
         m++;
        while(strncmp(x,corsa[m].partenza,l)==0){
             printf("%s %s %s %s %s %s %d\n",corsa[m].codice,corsa[m].partenza,corsa[m].destinazione,corsa[m].data,corsa[m].ora_partenza,corsa[m].ora_arrivo,corsa[m].ritardo);
             m++;
        }
        pos--;
        m=pos;
       while(strncmp(x,corsa[m].partenza,l)==0){
        printf("%s %s %s %s %s %s %d\n",corsa[m].codice,corsa[m].partenza,corsa[m].destinazione,corsa[m].data,corsa[m].ora_partenza,corsa[m].ora_arrivo,corsa[m].ritardo);
             m--;
        }
        
        found=1;
        
        }
        
       
}
 if(found==0){
            printf("non trovato\n");
        }
}