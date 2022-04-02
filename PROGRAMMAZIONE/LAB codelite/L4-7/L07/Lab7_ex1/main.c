#include <stdio.h>
#include <stdlib.h>
#define K 2 

typedef struct {
    int u;
    int v;
}COPPIE;



void leggi_file(int*N,int *E,COPPIE** arco);
int powerset_disp(int *val, int pos, int *sol,int N,int count ,int E,COPPIE * arco);
int check(int res[],int E,int c, COPPIE *arco);
int main()
{
    int N,E;
    COPPIE * arco;
  
   leggi_file(&N,&E,&arco);
  
  
  int *val=malloc(N*sizeof(int));
  
  for(int i=0;i<N;i++){
      val[i]=i;
  }
  
  int *sol=malloc(N*sizeof(int));
  int pos=0;
  int count=0;
  
  printf("vertex cover:\n");
  count=powerset_disp(val,pos,sol,N,count,E,arco);
  printf("numero vertex cover=%d\n",count);
  free(sol);
  free(val);
  free(arco);

  

	return 0;
}

void leggi_file(int*N,int *E,COPPIE **arco){
    
    COPPIE *s;
  
    int i;
    FILE *fg=fopen("grafo.txt","r");
    if(fg==NULL) exit(1);
    
    fscanf(fg,"%d %d", N,E);
    
    
   s=malloc((*E)*sizeof(COPPIE));
   
    
    for( i=0;i<*E;i++){
        fscanf(fg,"%d %d",&s[i].u,&s[i].v);
       
    }

    *arco=s;
    
 
}


int powerset_disp(int *val, int pos, int *sol,int N,int count,int E,COPPIE *arco){
int res[N];

  int i,j;
    if(pos>=N){
            
            for(i=0;i<N;i++){
            res[i]=-1;
            }
            
            for(i=0,j=0;j<N;j++){
            
                if(sol[j]!=0){
                res[i]=val[j];
             
                i++;
            }
           
        }
        if(check(res,E,i,arco)==1){
         for(j=0;j<i;j++){
           
             printf("%d ",res[j]);
         }
         
          printf("\n\n");
         
        
        return count+1;
        }
        return count;
    }
    
    sol[pos]=0;
    count=powerset_disp(val,pos+1,sol,N,count,E,arco);
    sol[pos]=1;
    count=powerset_disp(val,pos+1,sol,N,count,E,arco);
    return count;
    
}

int check(int res[],int E, int c, COPPIE *arco){
    int found=0;
    int j=0;
    for(int i=0;i<E ;i++){
       // printf("ARCO %d %d\n",arco[i].u,arco[i].v);
        found=0;
        for(j=0;j<c && found==0;j++){
          //  printf("DA CONTROLLARE %d\n",res[j]);
            if(arco[i].u==res[j]){
                found=1;
                
            }
            else if(arco[i].v==res[j]){
                     found=1;
            }
        }
        if(found==0){
            break;
        }
    }        
          
        
    
    return found;
}