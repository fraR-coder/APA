#include <stdio.h>
#include <stdlib.h>
#define N 10
int main()
{
int V[N]={1, 3, 4, 0, 1, 0, 9, 4, 2, 0};
int A[N] , S[N]={0};
int i=0;
int l=0;
int j=0 , k=0;
int dim=0 ,maxdim=0;
int start=0;


for(i=0;i<N;i++){


	if (V[i]!=0){

		dim++;

		}


	if (V[i]==0){

            l=dim;
            dim=0;


			}



		if(l>=maxdim && l!=0){
                maxdim=l;
                A[j]=i;
                j++;
                l=0;
        }

}
printf("maxdim=%d\n",maxdim);



for(i=0;i<j;i++){

    start=A[i]-maxdim;
    for(j=0;j<maxdim;j++){
        S[j]=V[start];
        start++;
    }
    for(k=0;k<maxdim;k++){
    printf("%d ",S[k]);

    }
    printf("\n");





    }

	return 0;
}
