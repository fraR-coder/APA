#include <stdio.h>
#include <stdlib.h>

#define nmax 20
#define mmax 20



void stampa_tabella(FILE * fp, int  mat[][mmax], int nr , int nc);

void conta_giornata( int mat[][mmax], int nr , int nc);
int main()
{
    FILE *fp;

int mat[nmax][mmax];
int i=0;
int j;
int nr;
int nc;


fp=fopen("mat.txt","r");
    if(fp==NULL){
        printf("error");
       exit(1);
    }

 fscanf(fp,"%d %d",&nr,&nc);

stampa_tabella( fp, mat,  nr ,  nc);

conta_giornata(mat,nr,nc);
 
 

return 0;
}

void stampa_tabella(FILE * fp, int  mat[][mmax], int nr , int nc){
    
    int i;
    int j;
   
 
    for (i=0;i<nr;i++){
        for(j=0;j<nc;j++){
            fscanf(fp,"%d",&mat[i][j]);
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return;
}


void conta_giornata( int mat[][mmax], int nr , int nc){
    
    int i;
    int j;
    int k=1;
    int t;
    int max=0;
    int res[nr];
    int pos;
    
    for(j=0;j<nr;j++){
        res[j]=0;
    }
    for(j=0;j<k && k<=nc;j++){
        for(i=0;i<nr;i++){
            
            res[i]+=mat[i][j];
            
            
        }
        for(t=0;t<nr;t++){
            if(res[t]>max){
                max=res[t];
                pos=t;
                
            }
        }
        printf("vincitore giornata %d = squadra %d\n", k-1, pos);
        
        k++;
    }
    return;
}