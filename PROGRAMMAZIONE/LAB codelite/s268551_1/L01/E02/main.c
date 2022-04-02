#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 200
#define Smax 30


typedef struct{
    char parola_d[L];
    char codice[L];
    
}Dizionario;


void crea_nuovo( FILE *fs, FILE *fr, Dizionario line[],int n);
void sostituisci( char riga[], Dizionario line  ,int dim1, int dim2,  int pos);



int main()
{
    int i=0;
     FILE  *fd;
     FILE *fs;
     FILE *fr;
     Dizionario linea[Smax];
     int S;


fd=fopen("dizionario.txt","r");
    if(fd==NULL){
        printf("error");
       exit(1);
    }
    
    fscanf(fd,"%d",&S);
    
    for(i=0;i<S;i++){                            //creo il dizionario
        fscanf(fd,"%s%s",linea[i].codice,linea[i].parola_d);
    }
        
        fs=fopen("sorgente.txt","r");
        if(fs==NULL){      
        printf("error");
        exit(1);
        }
                                                                        //apro file
         fr=fopen("ricodificato.txt","w");
        if(fr==NULL){
        printf("error");
        exit(1);
        }
    
        crea_nuovo(fs,fr,linea,S);
        fclose(fd);
        fclose(fs);
        fclose(fr);
    
	return 0;
}



 void crea_nuovo(FILE *fs, FILE *fr, Dizionario line[],int n){

char riga[L+1];
int i=0; 
int dim_c=0;
int dim_p=0;
int dim_r=0;
int j=0;
int k=0;
int ok=0;


     
        
        while(fgets(riga, L+1, fs) != NULL){                            //scorro le righe file sorgente
        dim_r=strlen(riga);
         for(k=0;k<dim_r;k++){                                              //scorro le lettere del file sorgente
            for(i=0;i<n;i++){                                                       //scorro parole dizionario
               j=0;
                 dim_p=strlen(line[i].parola_d);
                dim_c=strlen(line[i].codice);

           
        
            if(riga[k]==line[i].parola_d[j]){
                
                ok=1;
                for(j=1;j<dim_p && ok==1;j++){                      
                   
                    if( riga[j+k]!=line[i].parola_d[j]){
                        
                        ok=0;
                    }
                }
            }
            
            
            if(ok){
                
                sostituisci(riga,line[i],dim_c,dim_p,k);
            
              
            }
            ok=0;
            
 
    }
         }
             fprintf(fr,"%s",riga);
                printf("%s\n",riga);
        
        }


}

void sostituisci( char riga[], Dizionario line  ,int dim1, int dim2, int pos){
    
    int dim_r=strlen(riga);
    int i=0;
    int j=0;
    
       if(dim1<=dim2){
                for( i=0;i<dim1 ;i++){                                          //sostituisco codice
                    riga[pos+i]=line.codice[i];
                    
                }
                 for(j=pos+i;j<dim_r;j++){                                          //sposto linea
                   riga[j]=riga[j+dim2-dim1];
               }
                }
                
                
               else if(dim1>dim2){
                     for(i=0;i<dim_r-pos-dim2+1;i++){                                   //sposto linea
                         riga[dim_r+dim1-dim2-i]=riga[dim_r-i];
                        
               }
                      for( j=0;j<dim1;j++){                                                                             //sostituisco codice
                    riga[pos+j]=line.codice[j];
                }
                }
               
    
}