#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solveR(char *str, char **dict, int*sol,int n, int s,int pos,int f ,int l,int *q) {
int j,c,ok;
int lun;
int k,i;
char tmp[l];char vet[l];

   
        lun=0;
        for(k=0;k<pos;k++){
        strcpy(tmp,dict[sol[k]]);
     
        j=0;
        while(tmp[j]!='\0') {
            vet[j+lun]=tmp[j];
            j++;
        }
            lun+=strlen(tmp);
            }
            
        if(lun>l) return f;
        
    
    
     if(lun==l){   
    if(strncmp(vet,str,l)==0){
        printf("s=%d\n",s);
    for(i=0;i<=k-1;i++)
        printf("%s ",dict[sol[i]]);
        f=1;
        return f;
    }
    
     }
         
       

 if(pos>=l) return f;
  
            
            for(i=0;i<n && f==0;i++){
                c=0;ok=1;
                sol[pos]=i;
                q[i]++;
                for(k=0;k<n && ok==1;k++){
                    if(q[k]!=0){
                        c++;
                    }
                    if(c>s) ok=0;
                }
                if(ok==0){
                    q[i]--;
                    continue;
                }
              
                f=solveR(str,dict,sol,n,s,pos+1,f,l,q);
                q[i]--;
            }

    
return f;

}

void solve(char *str, char **dict, int n, int s) {
    int l=strlen(str);
    int *sol=malloc(l*sizeof(int));
    int*q=calloc(n,sizeof(int));
    int f=0;
    if(!solveR(str,dict,sol,n,s,0,f,l,q)) printf("s=%d\nnessuna soluzione",s);


}



int main(){
    int n=8;
    char *str="abracadabra";
    char*dict[8]={"a", "ab", "cada", "abra", "ra", "da", "ca","bra"};
    int s=3;

    solve(str,dict,n,s);
    
	
	return 0;
}
