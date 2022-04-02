#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define K 3
#define user_input 0

float punti=0;
float giusta=1;
float sbagliata =-0.33;
float bianca=0.0;
int N=30;
float soglia=18;

float calcola_punti(int numero_giuste, int numero_sbagliate, int numero_bianche){
	return ((numero_bianche*bianca)+(numero_giuste*giusta)+(numero_sbagliate*sbagliata));
}
void stampa_punteggi(int numero_giuste, int numero_sbagliate, int numero_bianche,float punti){
	 if(punti>=soglia){
		printf("%d	 	%d 		%d 		(%f)",numero_giuste,numero_sbagliate,numero_bianche,punti);
        printf("\n");
	 }
}

int comb_ripet(int pos, float *val, float *sol, int n, int start,int count) {
  int i;
  if (pos >= n) {
      
      int a=0;
	  int b=0;
	  int c=0;
      
    for (i=0; i<n; i++){
        if(sol[i]==giusta) a++;
        if(sol[i]==sbagliata) b++;
        if(sol[i]==bianca) c++;
    }
    punti=calcola_punti(a,b,c);
    
	stampa_punteggi(a,b,c,punti);
    
  
  return count+1;
  }
  
  
  for (i=start; i<K; i++) {
    
      
      
    sol[pos] = val[i];
    count = comb_ripet(pos+1, val, sol, n, start,count);
    start++;
  }
  return count;
}

void add_info(){
	printf("quante domande ci sono?\n");
	scanf("%d",&N);
	printf("inserisci i punteggi delle singole domande:\ncorretta:\n");
	scanf("%f",&giusta);
	printf("sbagliata:\n");
	scanf("%f",&sbagliata);
	printf("bianca:\n");
	scanf("%f",&bianca);
	printf("qual e' la soglia?\n");
	scanf("%f",&soglia);
}

int main(){
    
    if(user_input)
      add_info();
      
	  float*sol=calloc(N,sizeof(float));
    int pos=0;
    float val[K]={giusta,sbagliata,bianca};
    printf("giuste	    sbagliate	     bianche	   punteggio totale\n------------------------------------------------------------------\n");
    int x= comb_ripet(pos,val, sol, N, 0,0) ;
    
    free(sol);
    return 0;
}


