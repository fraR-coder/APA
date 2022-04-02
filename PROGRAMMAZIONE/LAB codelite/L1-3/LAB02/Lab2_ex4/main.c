#include <stdio.h>

#define N 40

void selection_sort(int V[],int dim);
void inserction_sort(int V[],int dim);
void shell_sort(int V[],int dim);

int main()
{
    int n;
    
    FILE * fp;
    int V[N];
    
    fp=fopen("sort.txt","r");
    int i=0;
    int j,k;
    int S;
    
    fscanf(fp,"%d",&n);
    
    for(i=0;i<n;i++){
        fscanf(fp,"%d",&S);
        for(j=0;j<S;j++){
            fscanf(fp,"%d",&V[j]);
           
        }
         printf("vettore non ordinato V:\n");
        for(k=0;k<S;k++){
            printf("%d  ",V[k]);
        }
        printf("\n\n");
        
       selection_sort(V,S);
       inserction_sort(V,S);
         shell_sort(V,S);
         
    }
    

    
	
	return 0;
}


void selection_sort(int V[],int dim){
    
    int i,j,a;
    int tmp[dim];
    int min=0;
        int n_scambi=0;
        int n_esterno=0;
        int n_interno=0;
    
    for(i=0;i<dim;i++){
        tmp[i]=V[i];
    }
    
    for(i=0;i<dim-1;i++){
        n_esterno++;
        min=i;
        for(j=i+1;j<dim;j++){
            n_interno++;
            if(tmp[j]<tmp[min]){
            min=j;
            }
        }
            if(min!=i){
                a=tmp[i];
                tmp[i]=tmp[min];
                tmp[min]=a;
                n_scambi++;
            
            }
            
        }
  
       /* printf("vettore  ordinato con selection sort:\n");
       for(i=0;i<dim;i++){
            printf("%d  ",tmp[i]);
        }
        */
     printf("selection sort\n");
     printf("numero di scambi=%d, numero iterazioni ciclo interno=%d, numero iterazioni ciclo esterno=%d, numero iterazioni totali=%d",n_scambi,n_interno,n_esterno,n_interno+n_esterno);
     printf("\n\n");
    
}







void inserction_sort(int V[],int dim){
    int i,j,a;
    int tmp[dim];
    int min=0;
        int n_scambi=0;
        int n_esterno=0;
        int n_interno=0;
    
    for(i=0;i<dim;i++){
        tmp[i]=V[i];
    }
    
    for(i=1;i<dim;i++){
        n_esterno++;
        a=tmp[i];
        j=i-1;
        while(j>=0 && a<tmp[j]){
            tmp[j+1]=tmp[j];
            j--;
            n_scambi++;
            n_interno++;
        }
        tmp[j+1]=a;
        
        }
    
   /*   printf("vettore  ordinato con selection sort:\n");
       for(i=0;i<dim;i++){
            printf("%d  ",tmp[i]);
        }*/
        
     printf("inserction sort\n");
     printf("numero di scambi=%d, numero iterazioni ciclo interno=%d, numero iterazioni ciclo esterno=%d, numero iterazioni totali=%d",n_scambi,n_interno,n_esterno,n_interno+n_esterno);
     printf("\n\n");
    
    
    
    
}

void shell_sort(int V[],int dim){
int i,j,a;
    int tmp[dim];
    int min=0;
        int n_scambi=0;
        int n_esterno=0;
        int n_interno=0;
        int n_tot=0;
        int h=1;
    for(i=0;i<dim;i++){
        tmp[i]=V[i];
    }
    
    printf("shell sort\n");
    while(h<dim/3){
        h=3*h+1;
    }
    while(h>=1){
         for (i =h; i <dim; i++) {
      n_esterno++;
      a = tmp[i];
      j = i;
      while (j >= h && a < tmp[j-h]) {
        tmp[j] = tmp[j-h];
        j -=h;
        n_interno++;
        n_scambi++;
      }
        tmp[j] = a;
    }
    printf("numero iterazioni ciclo esterno per h = %d: %d\n", h, n_esterno);
    h = h/3;
    n_tot +=n_esterno;
    n_esterno=0;

  }
  printf("numero di scambi=%d, numero iterazioni ciclo interno=%d, numero iterazioni ciclo esterno=%d, numero iterazioni totali=%d",n_scambi,n_interno,n_tot,n_interno+n_tot);
     printf("\n\n");
}
        
    
    
    



