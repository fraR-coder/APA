#include <stdio.h>
#include <stdlib.h>


#define DBG 0

int** creaMatrice(int r,int c){
    
    int**M=malloc(r*sizeof(int*));
    for(int i=0;i<r;i++){
        M[i]=malloc(c*sizeof(int));
   
    }
    
    M[0][0]=0; M[0][1]=1; M[0][2]=2; M[0][3]=2;
    M[1][0]=2; M[1][1]=2; M[1][2]=4; M[1][3]=4;   
    M[2][0]=3; M[2][1]=1; M[2][2]=2; M[2][3]=2;   
    
    return M;
}

void change(int **M,int r, int c){
    int tmp[r][c];
    int i,j,m=0,n=0;
    
      for(i=0;i<r;i++){
        for(j=0;j<c;j++){
           tmp[i][j]=M[i][j];
        }
    }
if(DBG){
    printf("test tmp\n");
      for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",tmp[i][j]);
        }
        printf("\n");
    }
}   
      for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if((tmp[i][j]%2)!=0){
                n=m=0;
                while(n<c){
                    M[i][n]=1;
                    n++;
                }
                while(m<r){
                    M[m][j]=1;
                    m++;
                }
            }
    
        }
      }
      
      
}

void libera(int**M,int r, int c){

    for(int i=0;i<r;i++){
        free(M[i]);
    }
    free(M);
}

int main(int argc, char **argv)
{
    int i,j;
    int r=3;
    int c=4;
    int**M=creaMatrice(r,c);
    
	printf("matrice inizale\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
    
    change(M,r,c);
    
    printf("\nnuova matrice\n");
     for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
    
    libera(M,r,c);
	return 0;
}
