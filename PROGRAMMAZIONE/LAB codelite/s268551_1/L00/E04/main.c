#include <stdio.h>
#include <stdlib.h>

#define N 20
#define MAX 20

void leggi_stampa( FILE * fp, char name[N], int mat[][N], int nr, int nc);
int stampanewmatrix( int mat[][N], int dim, int nr, int nc); 
int main()
{
FILE *fp;
char name[N];
int mat[MAX][MAX];
int i=0;
int j;
int max=0;

int dim=1;
 int nr;
  int nc;


  printf("dimmi il nome del file\n");
 scanf("%s",name);
    fp=fopen(name,"r");
    if(fp==NULL){
        printf("error");
       exit(1);
    }

 fscanf(fp,"%d %d",&nr,&nc);

 leggi_stampa(fp,name,mat, nr,nc)   ;
 
  do{
     
     printf("dim=?\n");
     scanf("%d",&dim);
    if(dim<1 || dim>nr || dim>nc){
        exit(1);
    }
  
    max= stampanewmatrix(mat,dim,nr,nc);
      printf("la somma è %d\n",max);

  }while (dim<=nc && dim<=nr && dim>=1);
 
     fclose(fp);
     

	return 0;
}

void leggi_stampa( FILE * fp, char name[N], int mat[][N], int nr, int nc){
    
    int i;
    int j;
    
          for(i=0;i<nr;i++){
        for(j=0;j<nc;j++){
            fscanf(fp,"%d",&mat[i][j]);
            
        }
    }
     printf("%d %d\n",nr ,nc);
         for(i=0;i<nr;i++){
              for(j=0;j<nc;j++){
                  printf("%d ",mat[i][j]);
              }
              printf("\n");
         }
         return;
}
int  stampanewmatrix( int mat[][N], int dim, int nr, int nc){
    
    int max=0;
    int counter=0;
    int posx=0;
    int posy=0;
    int i,k,j,t;
    for(k=0;k<=nr-dim;k++){
        for(t=0;t<=nc-dim;t++){
            
    
    
            for(i=k;i<dim+k;i++){
                for(j=t;j<dim+t;j++){
             printf("%d ",mat[i][j]);
             counter+=mat[i][j];
        }
        printf("\n");
    }
    if (counter>max){
        max=counter;
        posx=i-dim;
        posy=j-dim;
    }
    counter=0;
    printf("---------\n");
}


    }
    printf("la matrice cercata  :\n");
    for(i=posx;i<dim;i++){
        for(j=posy;j<dim;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return max ;
}