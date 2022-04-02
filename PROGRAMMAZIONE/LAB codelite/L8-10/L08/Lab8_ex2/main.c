#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define NOMEFILE "test_set.txt"

#define N 4


char *res;

int calcola_val(int*valore,char *sol, int count);

int check2(char *sol,int pos);
void ottimizza(int v_c,int count,char *sol,int* best);
int check(char x, char y,char *sol,int pos,int max_rip,int *mark);

int perm_rep(char *val, int pos, char *sol,int max_val,int *mark,int k,int best,int *finish,int max_rip, int *valore);

int main()
{
    int R;
    int i,j;
    int n_tot;
    int mark[N];
    int valore[N];
    char val[N+1]={'Z','R','T','S','\0'};
    char *sol;
    int finish;
    int max_rip;
    int max_val;
 
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
        for(j=0;j<N;j++){
            fscanf(fp,"%d",&valore[j]);
            max_val+=(valore[j]* mark[j]);
        }
        fscanf(fp,"%d",&max_rip);
        
         sol=malloc(n_tot*sizeof(char));
         finish=1;
        best=perm_rep(val,0,sol,max_val,mark,N,best,&finish,max_rip,valore);
        printf("valore max %d\nSequenza:\n",best);
       
         printf("%s",res);
     
    printf("\n\n");
        free(sol);
        
        
        
        
    }
  
   
    
 
	return 0;
}


int perm_rep(char *val, int pos, char *sol,int max_val,int *mark,int k,int best,int *finish,int max_rip, int *valore){
    
int v_c=0;
    
if(best>=max_val){
  
 
   *finish=0;
    return best ;
}

 
 
    for(int i=0;i<k && (*finish)!=0 ;i++){
        
        if(mark[i]>0){
            
            sol[pos]=val[i];
            
            if(pos==0){
                
                 mark[i]--;
               best=perm_rep(val,pos+1,sol,max_val,mark,k,best,finish,max_rip,valore);
                mark[i]++;
            }
           
           else{

            if(check(sol[pos-1],sol[pos],sol,pos,max_rip,mark)==1){
           
        
            mark[i]--;
           best=perm_rep(val,pos+1,sol,max_val,mark,k,best,finish,max_rip,valore);
            mark[i]++;
            }
           else {
               
               if( check2(sol,pos) ==1){
                  v_c=calcola_val(valore,sol,pos);
                   
                ottimizza(v_c,pos,sol,&best);
               }
             
               
           }
            
           }
        }    
        
        
     
    }
    
    if( check2(sol,pos) ==1){
                    v_c=calcola_val(valore,sol,pos);
                ottimizza(v_c,pos,sol,&best);
               }
    
    return best;
    

}

int check(char x, char y,char *sol,int pos,int max_rip, int *mark){
    
    int i;
    int nz=0;
    int ns=0;
    int nr=0;
    int nt=0;
    int Nz=0;
    int Ns=0;
 
    
    if(y=='Z'){
            if(x!='T' && x!='Z') return 0;
            
            for( i=pos-max_rip; i>=0 && i<pos+1 ;i++){
                  if(sol[i]=='Z')  nz++;
          
            }
        
        }                                                      
     else if(y=='S'){                          
            if(x!='S' && x!='R') return 0;
            
           for( i=pos-max_rip; i>=0 && i<pos+1 ;i++){
                  if(sol[i]=='S')  ns++;
        }                                             
     }                                             
         else if(y=='R'){                      
            if(x!='Z' && x!='T') return 0;
            
            for( i=pos-max_rip; i>=0 && i<pos+1 ;i++){
                  if(sol[i]=='R')  nr++;
        }   
         }
   else   if(y=='T'){                          
            if(x!='S' && x!='R') return 0;
            
            for( i=pos-max_rip; i>=0 && i<pos+1 ;i++){
                  if(sol[i]=='T')  nt++;
        }     
   }
for( i=0;i<pos+1;i++){
     if(sol[i]=='Z')  Nz++;
     if(sol[i]=='S') Ns++;
}
if(Nz>Ns){
    if(Nz>Ns+mark[3]){
        mark[0]=0;
        return 0;
    }
}



if( (nz >max_rip) ||   (ns >max_rip) ||  (nt >max_rip) || (nr >max_rip) ) return 0;



                       
  
  return 1;
    
}
    
void ottimizza(int v_c,int count,char *sol,int* best){
    
   
    int j;
     if(v_c>*best){
            
                   *best=v_c;
                   if(res!=NULL) free(res);
         
                    res=malloc((count+1)*sizeof(char));
                    for( j=0;j<count;j++){
                    res[j]=sol[j];
                    }
                    res[j]='\0';
               }
     
}

int check2(char *sol,int pos){
    
     int Nz=0;
    int Ns=0;
    
     for(int i=0;i<pos;i++){
                 if(sol[i]=='Z')  Nz++;
                 if(sol[i]=='S')  Ns++;
            }   
            if(Nz>Ns) return 0;
            
            return 1;
}

int calcola_val(int*valore,char *sol, int count){
    
    int i;
    int v_c=0;
    for(i=0;i<count;i++){
        if(sol[i]=='Z') v_c+=valore[0];
        if(sol[i]=='R') v_c+=valore[1];
        if(sol[i]=='T') v_c+=valore[2];
        if(sol[i]=='S') v_c+=valore[3];
    }
    return v_c;
    
}