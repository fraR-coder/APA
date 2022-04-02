#include <stdio.h>

int gcd(int a, int b);

int main()
{
    int a=20;
    int b=68;
    
    int x= gcd(a,b);
    
    printf("gcd(%d,%d) = %d\n", a,b,x);
    
    printf("%d\n",8/2);

	return 0;
}


int gcd(int a, int b){
    
    int x;

    if(a==b || b==0){
        return a;
    }
    
    if(a>b){
        if(a%2 ==0 && b%2==0){
            x=2*gcd(a/2,b/2);
            return x;
            
        }
        else if((a+1)%2==0 && (b+1)%2==0){
            x=gcd((a-b)/2,b);
            return x;
        }
        else if((a+1)%2==0 && b%2==0){
            x=gcd(a,b/2);
            return x;
        }
        else{
              x=gcd(a/2,b);
            return x;
        }
    }
    else if(a<b){
        
        x=gcd(b,a);
        return x;
    }
    

    
}