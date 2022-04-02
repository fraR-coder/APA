#include <stdio.h>
#include <stdlib.h>

#define MAXC 50
#define MAXR 50


void leggimatrice(int M[][MAXC],  int *nr, int *nc);
int riconosciRegione(int mappa[][MAXC],int nr,int nc,int r,int c,int *b,int *h);
int main()
{
    
	int mappa[MAXR][MAXC],i, nr, nc,r,c,b,h;
    
    
    
   leggimatrice(mappa,&nr,&nc);
   
   while(r!=-1 && c!=-1){
   printf("dimmi le cordinate (partendo da 0) oppure -1\n");
   scanf("%d%d",&r,&c);
   
   if(r==-1 || c==-1){
       printf("finito");
       return 1;
   }
    
  
    if( riconosciRegione(mappa,nr,nc,r,c,&b,&h)){
      printf("regione del punto in posizione (%d,%d), base %d e altezza %d\n\n",r,c,b,h);
      
    
  }
   
   }
   

   
    
	return 0;
}

void leggimatrice(int M[][MAXC],int *nr, int *nc){
    
    int i, j;
  FILE *fp = fopen("mappa.txt", "r");
  if (fp == NULL){
    exit(-1);
  }
  
  fscanf(fp,"%d %d",nr,nc);
  
  printf("%d %d\n",*nr,*nc);
  
  for(i=0;i<*nr;i++){
        for (j=0;j<*nc;j++){
            fscanf(fp,"%d",&M[i][j]);
        }
    }
    
    for(i=0;i<*nr;i++){
        for (j=0;j<*nc;j++){
            printf("%d",M[i][j]);
        }
        printf("\n");
    }
  

}


int riconosciRegione(int mappa[][MAXC],int nr,int nc,int r,int c,int *b,int *h){
    
    int i,j;
    int tmp=0;
    int stop=0;
    int sx=0;
    int su=0;
    if(mappa[r][c]==0){
        return 0;
    }
    else{
        for(i=r;i<=nr && stop==0;i++){
                                                                        //guardo giù
            if(mappa[i][c]==1){
                    tmp++;
            }
            if(mappa[i][c]!=1){                                  
                    stop=1;
            }
        }
            stop=0;
             
            for(i=r-1;i>=0 && stop==0;i--){
          
                                                                            //guardo su
            if(mappa[i][c]==1){
                    tmp++;
                    su++;
            }
            if(mappa[i][c]!=1){                                  
                    stop=1;
            }
            }
            
            *h=tmp;
            stop=0;
            tmp=0;
            
        
        
         for(j=c;j<=nc && stop==0;j++){                  //guardo  dx
                    if(mappa[r][j]==1){
                    tmp++;
                    }
                     if(mappa[r][j]!=1){                                  
                    stop=1;
                    }
                }
                stop=0;
                
                for(j=c-1;j>=0 && stop==0 ;j--){                  //guardo sx
                    if(mappa[r][j]==1){
                    tmp++;
                    sx++;
                    }
                     if(mappa[r][j]!=1){                                  
                    stop=1;
                    }
                }
                
          *b=tmp;
           
    }
    
    if(sx!=0 || su!=0){
        printf("hai trovato un punto nero ma non e un estremo superiore sinistro\nl'estremo di quesat regione si trova in %d ,%d \n\n", r-su, c-sx);
        
    }

return 1;
}