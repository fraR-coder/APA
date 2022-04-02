#include <stdio.h>
# include <stdlib.h>
#include <string.h>

#define MAX 30
#define N 20
void ruota_r(int mat[][MAX],int nc);
void ruota_c(int mat[][MAX],int nr);

int main(void)
{
FILE *fp;
char name[N];
int mat[MAX][MAX];
 int nr;
  int nc;

  char selettore[N];
 
  int i=0;
  int j=0;


  printf("dimmi il nome del file\n");
 scanf("%s",name);
    fp=fopen(name,"r");
    if(fp==NULL){
        printf("error");
       exit(1);
    }

 fscanf(fp,"%d %d",&nr,&nc);
 printf("dimensione matrice: %dx%d\n",nr,nc );
 for(i=0;i<nr;i++){
     for(j=0;j<nc;j++){
         fscanf(fp,"%d",&mat[i][j]);
     }
 }
 printf("la matrice :\n");
 for(i=0;i<nr;i++){
     for(j=0;j<nc;j++){
         printf("%d ",mat[i][j]);
     }
     printf("\n");
 }
 do{
     
     printf("dati: selettore(riga/colonna) \n");
     scanf("%s",selettore);
     
       if(strcmp(selettore,"riga")==0){
        
     
     ruota_r(mat,nc);
      for(i=0;i<nr;i++){
     for(j=0;j<nc;j++){
         printf("%d ",mat[i][j]);
     }
     printf("\n");
 }
 printf("----------------------\n");
       }
       
       
          if(strcmp(selettore,"colonna")==0){
        
     
     ruota_c(mat,nr);
      for(i=0;i<nr;i++){
     for(j=0;j<nc;j++){
         printf("%d ",mat[i][j]);
     }
     printf("\n");
 }
 printf("----------------------\n");
       }
       
       
       
 }while(strcmp(selettore,"fine")!=0);
 

 
 
	return 0;
}


void ruota_c(int mat[][MAX],int nr){
    
    int box[MAX];
    int tmp[MAX];
    int i=0;
    int j=0;
    int indice;
    char direzione[N];
    int P;
   
    printf("dati: indice(posizione del vettore)  direzione(dx/sx/su/giu)  numeroposizioni\n");
   scanf("%d%s%d",&indice,direzione,&P);
   for(i=0;i<nr;i++){
       tmp[i]=mat[i][indice];
   }
     
    if (strcmp(direzione,"su")==0){ 
        
        
                for( j=0;j<nr-P;j++){
                box[j]=tmp[j+P];
            }
           
            
              for(i=0;i<P;i++){
                  box[nr-P+i]=tmp[i];
                 
        }
        
        
            for(j=0;j<nr;j++){
            mat[j][indice]=box[j];
        }
    
}

 if (strcmp(direzione,"giu")==0){ 
    
             
            for( j=0;j<P;j++){
                box[j]=tmp[nr-P+j];
            }
           
             for(i=0;i<nr-P;i++){
                  box[P+i]=tmp[i];
             
                 
        }
        for(i=0;i<nr;i++){
            mat[i][indice]=box[i];
        }
    
}
return;
    
}

void ruota_r(int mat[][MAX], int nc){
    
    int box[MAX];
    int tmp[MAX];
    int i=0;
    int j=0;
    int indice;
    char direzione[N];
    int P;
   
    printf("dati: indice(posizione del vettore)  direzione(dx/sx/su/giu)  numeroposizioni\n");
   scanf("%d%s%d",&indice,direzione,&P);
   for(i=0;i<nc;i++){
       tmp[i]=mat[indice][i];
   }
       
   
    if (strcmp(direzione,"sinistra")==0){ 
        
        
                for( j=0;j<nc-P;j++){
                box[j]=tmp[j+P];
            }
           
            
              for(i=0;i<P;i++){
                  box[nc-P+i]=tmp[i];
                 
        }
        
        
            for(j=0;j<nc;j++){
            mat[indice][j]=box[j];
        }
    
}

 if (strcmp(direzione,"destra")==0){ 
    
             
            for( j=0;j<P;j++){
                box[j]=tmp[nc-P+j];
            }
           
             for(i=0;i<nc-P;i++){
                  box[P+i]=tmp[i];
             
                 
        }
        for(i=0;i<nc;i++){
            mat[indice][i]=box[i];
        }
    
}
return;
}