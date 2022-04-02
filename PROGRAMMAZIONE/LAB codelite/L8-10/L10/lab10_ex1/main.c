#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define NOME "att2.txt"


typedef struct{
    int si,fi;
}elenco;


int massimo(int a,int b){
    
    if(a>b) return a;
    
    return b;
}
int durata(elenco a){
    return a.fi-a.si;
}




int leggi_file(elenco** attivita){
    
    elenco *s;
  
    int i;
    int N;
    FILE *fs=fopen(NOME,"r");
    if(fs==NULL) exit(1);
    
    fscanf(fs,"%d",&N);
    
    
   s=(elenco*)malloc((N+1)*sizeof(elenco));
   
   
    
    for( i=1;i<=N;i++){
        fscanf(fs,"%d %d",&s[i].si,&s[i].fi);
       
    }

    *attivita=s;
    fclose(fs);
    
    return N;
 
}



void ordina_att(elenco * attivita,int N){
    
    elenco tmp;
    int i,j;
    int min;
    int flag=0;
    
    for(i=1;i<=N-1;i++){
        min=attivita[i].si;
        
        for(j=i+1;j<=N;j++){
            if(attivita[j].si<min){
                min=attivita[j].si;
                flag=j;
            }
            
        }
        if(min!=attivita[i].si){
            tmp=attivita[i];
            attivita[i]=attivita[flag];
            attivita[flag]=tmp;
        }
            
        }
        
    }

int alternativa(elenco *attivita,int i, int j,int N,int *comp);
int progr_dim(elenco * attivita, int N);
int main()
{
    elenco *attivita;
    int N;
  
    
    N=leggi_file(&attivita);
      
    for(int i=1;i<=N;i++){
        printf("%d %d\n",attivita[i].si,attivita[i].fi);
    }
    
    ordina_att(attivita,N);
    
    printf("attivita ordinate con selection sort\n");
    for(int i=1;i<=N;i++){
        printf("%d %d\n",attivita[i].si,attivita[i].fi);
    }
    
    int a =progr_dim(attivita,N);

    printf("massimo possibile=%d\n",a);
	
	return 0;
}



int alternativa(elenco *attivita,int i, int j,int N,int *comp){

int c=0;
int k;
int max=0;

    for(j=i-1 ; j>=1;j--){
         if (attivita[j].fi <= attivita[i].si){
             
             if(comp[i]==0) comp[i]=j;
            
             k=j;
             while(k>0){
                 
             c+=durata(attivita[k]);
             k=comp[k];
             
                                
        }
        
        if(c>max) {
            max=c;
            comp[i]=j;
        }
        c=0;
    
        }
    }

    return max;
}

int progr_dim(elenco * attivita, int N){
    
    int i,j,k;
    int *opt=calloc(N+1,sizeof(int));
    int *comp=calloc(N+1,sizeof(int));

    
    int c;
  
   opt[0]=0;
   
for(i=1;i<=N;i++){
    c=alternativa(attivita,i,j,N,comp);
    opt[i]=massimo(opt[i-1],durata(attivita[i])+c);
        }
    
/*for(i=0;i<=N;i++){
    printf("%d ",comp[i]);
}
printf("\n");

for(i=0;i<=N;i++){
    printf("%d ",opt[i]);
}
printf("\n");
 */
printf("attivita selezionate\n");

j=N;
c=0;

for(int k=N;comp[k]!=0;k--){
    j=k;
    while(j>0){
    
        c+=durata(attivita[j]);
        j=comp[j];
    }
    if(c==opt[N]){
       i=k;
        while(i>0){
        printf("%d %d\n",attivita[i].si,attivita[i].fi);
    
        i=comp[i];
        }
        return opt[N];
    }
    c=0;
}


    
  
  return opt[N];
    
}


