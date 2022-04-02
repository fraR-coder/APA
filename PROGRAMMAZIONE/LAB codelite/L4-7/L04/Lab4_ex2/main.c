#include <stdio.h>
#include <stdlib.h>
#define N 10
int count(int *a, int x,int n);
int majority( int *a, int n);
int majority1( int *a, int l, int r);
int main()
{
 int a[N]={2,2,3,2,2,3,2,2,4,1};

 int x=-1;

 

 x=majority(a,N);

     
      if(x!=-1){
 
    
 printf("l'elemento maggioritario = %d\n",x);
      }
 else 
     printf("l'elemento maggioritario non trovato\n");
 
	
	return 0;
}

int majority( int *a, int n){
   
     int l=0;
    int r=n-1;
    
  
    int x;
    
   
    x=majority1(a,l,r);
    
     
     
    return x;

}

int majority1( int *a, int l,int r){
    
    int res=-1;
    int xl,xd;
    int ris_l,ris_d;
    int m=(l+r)/2;

    if(l==r){
        return a[l];
    }
    
     
    xl=majority1(a,l,m);
 
    xd=majority1(a,m+1,r);
    ris_l=count(a,xl,N);
    ris_d=count(a,xd,N);
    
    if(ris_l>N/2){
        res=xl;
        return res;
    }
    if(ris_d>N/2){
      res=xd;
        return res;
    }
    return res;

      
  
}


int count(int *a, int x,int n){
    int i;
    int cnt=0;
    for(i=0;i<n;i++){
        if(a[i]==x){
            cnt++;
        }
    }
    return cnt;
 
}