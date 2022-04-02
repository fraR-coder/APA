#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXS 20 // numero max di sequenze
#define MAXL 5  // lungh. max di sequenza
#define MAXR 200 // lungh max riga nel testo
#define MAXP 25 // lungh. max parola testo
#define N 10  //numero max di parole per ogni sequenz



typedef struct{
    char sequenza[MAXL+1];
    char parola[MAXR][MAXP+1];
    int pos[MAXR];
}Soluzione;

void cerca(FILE *ftesto,int S, Soluzione sol[]);
int main()
{
 int i,j;
     FILE  *fsequenze;
     FILE *ftesto;
    int S;
    int f=0;
    
  
    Soluzione sol[MAXS];

fsequenze=fopen("sequenze.txt","r");
    if(fsequenze==NULL){
        printf("error");
       exit(1);
    }
    
    //inizializzo i campi pos e parola della struttura soluzione  a 0
    for(i=0;i<N;i++){                                              
        for(j=0;j<MAXP;j++){
            strcpy(sol[i].parola[j],"0");
        }
        for(j=0;j<N;j++){
            sol[i].pos[j]=0;
        }
    }
    
    fscanf(fsequenze,"%d",&S);
    

    for(i=0;i<S ;i++){                            //riempio il campo delle sequenze
        fscanf(fsequenze,"%s",sol[i].sequenza);
    }
   
   fclose(fsequenze);
        ftesto=fopen("testo.txt","r");
        if(ftesto==NULL){      
        printf("error");
        exit(1);
        }
        
        cerca(ftesto,S,sol);
        
        for(i=0;i<S ;i++){
            printf("la sequenza <%s> contenuta in ",sol[i].sequenza);
            f=0;
            for(j=0;  j<MAXR  ;j++){                                                               //stampo considerando che le parole si trovano in posizione con indice uguale all'indice del vettore posizione
                if(sol[i].pos[j]!=0){
                    f=1;
                    printf("<%s>  ", sol[i].parola[j] );
                    printf("posizione %d, ",sol[i].pos[j]);
                }
                }
                 if(f==0){{
                     printf("nessun a parola");
                 }
            }
            printf("\n\n\n");
        }
        fclose(ftesto);
        
	return 0;
}

void cerca(FILE *ftesto,int S, Soluzione sol[]){
    
    int i,j,t,h,g;
    int k=0;
    int found=0;
 
    
    char parola[MAXP+1];
    int count=0;
  
  

    for(g=0;g<MAXR ;g++){         //scorro le parole
        
        
        do{
            fscanf(ftesto,"%c",&parola[0]);                             //scorro finche non trovo un carattere alfanumerico
            
        
        }while (parola[0]!=EOF && !isalnum(parola[0]));
        
      if(parola[0]==EOF){
          exit(1);
      }
        
        i=0;
         do {
            i++;
    fscanf(ftesto, "%c", &parola[i]);                       //salvo le letetre nel vettore finche non trovo un segno di punteggiatura o spazio
   
    } while (parola[i]!=EOF && isalnum(parola[i]));
 if(parola[i]==EOF){
     exit(1);
 }
        parola[i] = '\0';
         
            
            
            
    

        
        count++;     //aumento conteggio parole
         
        
        for(i=0;i<strlen(parola) ;i++){ //scorre le lettere nella parola
            
          
           for(t=0;t<S;t++){   //scorre le sequenze
               
                if(toupper(parola[i])==toupper(sol[t].sequenza[0])){                                   //confronto la parola con la sequenza
                    found=1;
                    
                  for(j=1;j<strlen(sol[t].sequenza) && found==1;j++){
                      if(toupper(parola[i+j])!=toupper(sol[t].sequenza[j])){
                          found=0;
                      }
                }
                
            }
            if(found){
            
                
            if(sol[t].pos[k-1]==0){           // per non salavre le sequenze che si ripetpno più volte nella stessa parola
            strcpy(sol[t].parola[k],parola);
            sol[t].pos[k]=count;
        k++;
            }
               found=0;
            }


            }
           
            
            
            
        }
       
        
   }
    
   
 
}