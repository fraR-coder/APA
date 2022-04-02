#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define TILES "tiles.txt"
#define BOARD "board.txt"

typedef struct{
    char color1, color2;
    int val1,val2;
    int rot;
}tessera_s;


typedef struct{
    int indice;
    int rot;
    
}scacchiera_s;

tessera_s * tiles_solution;

void rotazione(tessera_s *p ){
    char tmp;
    int tmp1;
    
    if(p->rot==1){
        tmp=p->color2;
        p->color2=p->color1;
        p->color1=tmp;
        
        tmp1=p->val1;
        p->val1=p->val2;
        p->val2=tmp1;
        
    }
}

scacchiera_s** leggi_board(int* R, int* C,int *mark, tessera_s * tile){
    
    int i,j;
    scacchiera_s **b;
     FILE * fb=fopen(BOARD,"r");
    assert(fb!=NULL);
    
    fscanf(fb,"%d %d\n",R,C);
    
    b=malloc((*R)*sizeof(scacchiera_s*));

    for( i=0;i<*R;i++){
        b[i]=malloc((*C) * sizeof(scacchiera_s));
     
        
        for( j=0;j<*C;j++){
            
            fscanf(fb,"%d/%d ",&b[i][j].indice,&b[i][j].rot);
            tile[b[i][j].indice].rot=b[i][j].rot;
            rotazione(&tile[b[i][j].indice]);
            mark[b[i][j].indice]=1;
            
            
        }
    }
    fclose(fb);
    
    return b;
}


tessera_s* leggi_tessere(int*T){
    
    tessera_s* p;
    
    
    FILE * ft=fopen(TILES,"r");
    assert(ft!=NULL);
    
    fscanf(ft,"%d\n",T);
    p=malloc((*T)*sizeof(tessera_s));
    
    for(int i=0;i<*T;i++){
        fscanf(ft,"%c %d %c %d\n",&p[i].color1,&p[i].val1,&p[i].color2,&p[i].val2);
        p[i].rot=0;
    }
    
    fclose(ft);
    
    
    return p;
    
    
}

int calcola_punteggio(scacchiera_s ** board,int T,int R, int C, tessera_s*tiles){
    int i,j;
    int sum=0;
    int p_r=0;
    int p_c=0;
    
  //colonne
    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            if(board[i][j].indice==-1) break;
            p_r+=tiles[board[i][j].indice].val1;
            if(j>=C-1) break;
            if (tiles[board[i][j].indice].color1!=tiles[board[i][j+1].indice].color1){
                p_r=0;
                break;
            }
            
        }
        
        sum+=p_r;
        p_r=0;
        
    }
    
    
    //righe
        for(j=0;j<C;j++){
            for(i=0;i<R;i++){
                   if(board[i][j].indice==-1) break;
            p_c+=tiles[board[i][j].indice].val2;
            if(i>=R-1) break;
              if(tiles[board[i][j].indice].color2!=tiles[board[i+1][j].indice].color2){
                p_c=0;
                break;
            }
            
        }
        
        sum+=p_c;
        p_c=0;
        
    }
    
    return sum;
    
}




void completar(int pos, scacchiera_s **board,tessera_s *tiles, int R, int C, int T, int *mark, int *pmax,scacchiera_s **finale){

int i,j,k,p;
int m,n;

if (pos >= (R*C)) { 
	p = calcola_punteggio(board, T, R, C, tiles);
    if (p>*pmax) {
      *pmax=p;
      
       for (n=0; n<R; n++){
        for(m=0;m<C;m++){
            
            
          finale[n][m]=board[n][m];
          tiles_solution[finale[n][m].indice]=tiles[finale[n][m].indice];
          
      }
    
    }

    }
    return;
   
  
}
i=pos/C;
j=pos%C;

if (board[i][j].indice == -1){ 
    for (k=0; k<T; k++) {
      if (mark[k]!=1){
    //la prendo
        mark[k] = 1; 
        board[i][j].indice = k; 
        completar(pos+1, board, tiles, R, C, T, mark,pmax,finale);
        //la ruoto
       tiles[board[i][j].indice].rot = 1; 
        rotazione(&tiles[board[i][j].indice]);
        completar(pos+1, board, tiles, R, C, T, mark,pmax,finale);
        //la tolgo
      board[i][j].indice = -1;
      mark[k] = 0;
        }
    }
    
}
//piena
  else 
   completar(pos+1, board, tiles, R, C, T, mark,pmax,finale);
   
  
   
}



void completa_scacchiera(scacchiera_s **board,int R,int C, int T,tessera_s *tiles, int *mark){
    
    
    int pmax=0;
    int pos=0;
    tiles_solution=malloc(T*sizeof(tessera_s));
    
    scacchiera_s ** finale=malloc(T*sizeof(scacchiera_s*));
    for(int i=0;i<R;i++){
        finale[i]=malloc(C*sizeof(scacchiera_s));
    }
    
completar(pos,board,tiles,R,C,T,mark,&pmax,finale);
    
printf("max %d\nDISPOSIZIONE\n",pmax);
  for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
           printf("%c/%d  %c/%d    ",tiles_solution[finale[i][j].indice].color1,tiles_solution[finale[i][j].indice].val1,tiles_solution[finale[i][j].indice].color2,tiles_solution[finale[i][j].indice].val2);
      }
    printf("\n");
    
}

 for(int i=0;i<R;i++){
      
            free(finale[i]);
          
    
     }
     free(finale);
}



int main()
{
    int i,j;
	tessera_s *tiles;
    
    scacchiera_s ** board;
    int T,R,C;
    
   int* mark;
   
    tiles=leggi_tessere(&T);
    mark=calloc(T,sizeof(int));
    

    board=leggi_board(&R,&C,mark,tiles);


completa_scacchiera(board,R,C,T,tiles,mark);


   
   
    free(mark);
    free(tiles_solution);
    free(tiles);
     for( i=0;i<R;i++){
      
            free(board[i]);
          
    
     }
     free(board);
     
    
	return 0;
}
