#include <stdio.h>
#include <stdlib.h>

#define MAXC 50

typedef struct{
    int area;
    int base;
        int altezza;
}Posizione;

void stampa_mappa( FILE *fp, int mappa[][MAXC],   int nr , int  nc);
void calcoli(int posx,int posy, int dimx, int dimy, Posizione pos[][MAXC]);
void  cerca(int mappa[][MAXC], int nr,int nc, Posizione pos[][MAXC]);

int main()
{
   
    FILE *fp;
    int nr, nc;
      int max_h=0;
    int max_l=0;
    int max_a=0;
    int i,j;
    int mappa[MAXC][MAXC];
    Posizione pos[MAXC][MAXC];
    int x_h,x_a,x_b,y_a,y_h,y_b;
    
    fp=fopen("mappa.txt","r");
    if(fp==NULL){
        printf("error");
       exit(1);
    }

 fscanf(fp,"%d %d",&nr,&nc);
printf("dimensioni : %dx%d\n",nr,nc);
stampa_mappa( fp, mappa,  nr ,  nc);

cerca(mappa,nr ,nc,pos);


for( i=0;i<nr;i++){
    for(j=0;j<nc;j++){
         if(pos[i][j].altezza>max_h){
            max_h=pos[i][j].altezza;                                           //trovo i massimi e mi segno le posizioni
            x_h=i;
            y_h=j;
        }
          if(pos[i][j].base>max_l){
            max_l=pos[i][j].base;
            x_b=i;
            y_b=j;
        }
         if(pos[i][j].area>max_a){
            max_a=pos[i][j].area;
            x_a=i;
            y_a=j;
        }
    
   
    }
}

printf("Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n\n",x_b,y_b,pos[x_b][y_b].base,pos[x_b][y_b].altezza, pos[x_b][y_b].area);
printf("Max area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n\n",x_a,y_a,pos[x_a][y_a].base,pos[x_a][y_a].altezza,pos[x_a][y_a].area);
printf("Max altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n\n",x_h,y_h,pos[x_h][y_h].base,pos[x_h][y_h].altezza,pos[x_h][y_h].area);

fclose(fp);




	return 0;
}

void cerca(int mappa[][MAXC], int nr,int nc, Posizione pos[][MAXC]){
    int i,j,t,k;
    
    int posx;
    int posy;
    int dimx, dimy;
    int count=0;
    int stop=0;
   

    for(i=0;i<nr;i++){
        for(j=0;j<nc;j++){
            
            if(mappa[i][j]==1){
                
        //controllo quanti altri 1 ci sono a dx
                for(t=j;stop==0;t++){                 
                    if(mappa[i][t]==1){
                    count++;
                    }
                     if(mappa[i][t]!=1){                                  
                    stop=1;
                    }
                }
               
                dimx=count;
                posx=t-dimx-1;
                count=0;
                
    //controllo quanti 1 ci sono sotto            
                for(k=i;stop==1;k++){
                        if(mappa[k][posx]==1){
                            count++;
                        }
                        if(mappa[k][posx]!=1){
                           stop=0;
                        }
                }
                        
                        dimy=count;
                         posy=i;
                         
                        count=0;
            //riempio il rettangolo considerato di 2        
                    for(t=posy;t<posy+dimy;t++){
                        for(k=posx;k<posx+dimx;k++){                     
                               mappa[t][k]=2;
                        }
                    }
                 
                    
                    calcoli(posx,posy , dimx, dimy,pos );
                    
                
                  
                
            }
        }
    
    
    }
}

void calcoli(int posx,int posy, int dimx, int dimy ,Posizione pos[][MAXC]){

    
    
    pos[posy][posx].area=dimx*dimy;
    pos[posy][posx].base=dimx;                                              
    pos[posy][posx].altezza=dimy;
    
    

    
    
}

void stampa_mappa( FILE *fp, int mappa[][MAXC],   int nr , int  nc){
    
    int i=0;
    int j=0;
    
    for(i=0;i<nr;i++){
        for (j=0;j<nc;j++){
            fscanf(fp,"%d",&mappa[i][j]);
        }
    }
    
    for(i=0;i<nr;i++){
        for (j=0;j<nc;j++){
            printf("%d",mappa[i][j]);
        }
        printf("\n");
    }
}