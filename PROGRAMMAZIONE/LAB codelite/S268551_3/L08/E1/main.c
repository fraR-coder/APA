#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define NOMEFILE "hard_test_set.txt"
#define N 4

int finish=1;
char *res;


void ottimizza(int count,char *sol,int *best);
int check(char x, char y);
int perm_rep(char *val, int pos, char *sol,int n,int count,int *mark,int k,int best);
int main()
{
    int R;
    int i,j;
    int n_tot;
    int mark[N];
    char val[N+1]={'Z','R','T','S','\0'};
    char *sol;
 
 
    FILE *fp;
    fp=fopen(NOMEFILE,"r");
    assert(fp!=NULL);
    
    fscanf(fp,"%d",&R);
    for(i=0;i<R;i++){
        n_tot=0;
        int best=0;
        printf("test numero %d\n",i+1);
        for(j=0;j<N;j++){
            fscanf(fp,"%d",&mark[j]);
            n_tot+=mark[j];
        }
         sol=malloc(n_tot*sizeof(char));
        finish=1;
        best=perm_rep(val,0,sol,n_tot,0,mark,N,best);
        printf("lunghezza max %d\nSequenza:\n",best);
        for(int k=0;k<best;k++){
         printf("%c ",res[k]);
     }
    printf("\n\n");
        free(sol);
        
        
        
        
    }
  
   
    
 
	return 0;
}


int perm_rep(char *val, int pos, char *sol,int n,int count,int *mark,int k,int best){
    
if(pos>=n){
   count=pos;
   ottimizza(count,sol,&best);
   finish=0;
    return best ;
}

 
 
    for(int i=0;i<k && finish!=0 ;i++){
        
        if(mark[i]>0){
            
            sol[pos]=val[i];
            if(pos==0){
                
                 mark[i]--;
                best=perm_rep(val,pos+1,sol,n,count,mark,k,best);
                mark[i]++;
            }
           
           else{

            if(check(sol[pos-1],sol[pos])==1){
           
        
            mark[i]--;
            best=perm_rep(val,pos+1,sol,n,count,mark,k,best);
            mark[i]++;
            }
           else {
               
               count=pos;
                ottimizza(count,sol,&best);
             
               
               
           }
            
           }
        }    
     
    }
    
    return best;
    

}

int check(char x, char y){
    
    
 
    
    if(x=='Z'){
            if(y!='Z' && y!='R') return 0;
        }                                                      
     else if(x=='S'){                          
            if(y!='S' && y!='T') return 0;
        }                                             
                                                      
         else if(x=='R'){                      
            if(y!='S' && y!='T') return 0;
        }                                               
   else   if(x=='T'){                          
            if(y!='Z' && y!='R') return 0;
        }                                                
  
  return 1;
    
}
    
void ottimizza(int count,char *sol,int* best){
    
     if(count>*best){
                   *best=count;
                   if(res!=NULL) free(res);
         
                    res=malloc(*best*sizeof(char));
                    for(int j=0;j<*best;j++){
                    res[j]=sol[j];
                    }
               }
}
    
   
    
  