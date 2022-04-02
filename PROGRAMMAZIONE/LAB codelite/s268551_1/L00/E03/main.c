#include <stdio.h>
#include <stdlib.h>
# define maxN 30
void ruota(int V[maxN], int N, int P, int dir);
int main(void){


int N;
int v[maxN];

int P=1;
int dir=0;
int i=0;

printf("N=?\n");
scanf("%d",&N);
if(N>maxN){
printf("N troppo grande");
exit(1);
}
printf("V=?\n");
for(i=0;i<N;i++){

scanf("%d",&v[i]);
}



while (P!=0 && P<N){
    printf("P=?\nPremi 0 per uscire\n ");
    scanf("%d",&P);
        if(P<=0){
        printf("finito\n");
        exit(2);
    }
    printf("Direzione?\n");
    scanf("%d",&dir);
   
    if(dir!=1 && dir!=-1){
        
        printf("hai sbagliato a dare la direzione\n");
        exit(3);
        
    }
    
    
	ruota(v,N,P,dir);
    printf("\nIl nuovo vettore : ");
    for(i=0;i<N;i++){
    printf("%d ", v[i]);
    }
    printf("\n");
	
}
	return 0;
}

void ruota(int V[maxN], int N, int P, int dir){
    int box[N];
    int i=0;
    int j=0;
   
    if (dir==1){ //sx
        
            for( j=0;j<N-P;j++){
                box[j]=V[j+P];
            }
           
            
              for(i=0;i<P;i++){
                  box[N-P+i]=V[i];
                 
        }
        for(i=0;i<N;i++){
            V[i]=box[i];
        }
    
}
if (dir==-1){//dx
    
             
            for( j=0;j<P;j++){
                box[j]=V[N-P+j];
            }
           
             for(i=0;i<N-P;i++){
                  box[P+i]=V[i];
             
                 
        }
        for(i=0;i<N;i++){
            V[i]=box[i];
        }
    
}
return;
}