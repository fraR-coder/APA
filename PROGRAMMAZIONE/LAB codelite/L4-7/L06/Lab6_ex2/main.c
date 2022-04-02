#include <stdio.h>
#include <stdlib.h>

void leggi_file(int ***mat,int *nr,int *nc);
int ** leggi_file1(int *nr,int *nc );
void separa(int **mat, int nr, int nc,int **v0, int ** v1,int *nneri,int*nbianchi );

int main()
{
    int **mat;
    int nr,nc;
    int i,j;
    int *v0,*v1;
    int nneri,nbianchi;
    
   // leggi_file(&mat,&nr,&nc);
   mat= leggi_file1(&nr,&nc);
    
    for( i=0;i<nr;i++){
         for( j=0;j<nc;j++){
           
            printf("%d ",mat[i][j]);
             
         }
         printf("\n");        
    }
 printf("\n\n");


 separa(mat,nr,nc,&v0,&v1,&nneri,&nbianchi);
 
 printf("Il vettore contentente le caselle bianche :\n");
 for(i=0;i<nbianchi;i++){
     printf("%d ",v0[i]);
 }
 
 free(v0);
 printf("\n\n");
 printf("Il vettore contentente le caselle nere :\n");
  for(i=0;i<nneri;i++){
     printf("%d ",v1[i]);
 }
 free(v1);

for(i=0;i<nr;i++){
    free(mat[i]);
}
free(mat);
 
    
	return 0;
}

void leggi_file(int ***mat,int *nr,int *nc){
    FILE *fp;
    
    int ** p;
    int r,c;
    fp=fopen("mat.txt","r");
    if(fp==NULL) exit(1);
    
    fscanf(fp,"%d %d", &r,&c);
   
        p=(int **)malloc(r* sizeof(int*));
        for(int i=0;i<r;i++){
             p[i]=(int*)malloc(c*sizeof(int));
         for(int j=0;j<c;j++){
        
             fscanf(fp,"%d",&p[i][j]);
             
         }        
    }
 fclose(fp);
*nr=r;
*nc=c;
*mat=p;   
    
}


int ** leggi_file1(int *nr,int *nc ){
     FILE *fp;
        
        int ** p;
  
    int r,c;
    fp=fopen("mat.txt","r");
    if(fp==NULL) exit(1);
    
    fscanf(fp,"%d %d", &r,&c);
    
            p=(int **)malloc(r* sizeof(int*));
        for(int i=0;i<r;i++){
             p[i]=(int*)malloc(c*sizeof(int));
         for(int j=0;j<c;j++){
        
             fscanf(fp,"%d",&p[i][j]);
             
         }        
    }
 fclose(fp);
*nr=r;
*nc=c;

   return p; 
    
}

void separa(int **mat, int nr, int nc,int **v0, int ** v1,int *nneri,int*nbianchi ){
    
  
int scacchiera[nr][nc];
int i,j;
int *zeri=malloc(sizeof(int));
int *uni=malloc(sizeof(int));
int u=1;//contatore di uni
int z=1;//contatore di zeri

//inizializzo la matrice  a 1 (caselle nere ) e 0 (caselle bianche)
scacchiera[0][0]=1;

for (i=0;i<nr;i++){
         for(j=1;j<nc;j++){
           if(scacchiera[i][j-1]==1) scacchiera[i][j]=0;
           else scacchiera[i][j]=1;
         }
         
          if(scacchiera[i][j-1]==1) scacchiera[i+1][0]=0;
           else scacchiera[i+1][0]=1;
         
              
    }

for (i=0;i<nr;i++){
         for(j=0;j<nc;j++){
             if(scacchiera[i][j]==1){
                 uni=(int *)realloc(uni,u*sizeof(int)); //rialloco dinamicamente i vettori ogni volta che trovo un 1
                
                 uni[u-1]=mat[i][j];
                 
                 u++;
                 
             }
             
             else{
                zeri=(int *)realloc(zeri,z*sizeof(int)); //rialloco dinamicamente i vettori ogni volta che trovo un 0
                 
                 zeri[z-1]=mat[i][j];
                  
                 z++;
             }
         }
}

*v0=zeri;
*v1=uni;
*nneri=u-1;
*nbianchi=z-1;

}