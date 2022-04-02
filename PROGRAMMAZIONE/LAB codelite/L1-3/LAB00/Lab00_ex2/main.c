#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

int conta(char S[], int n);


int main()
{
FILE *fp;
char name[N];
int n;
char S[N+1];
int i=0;
int num=0;

int res=0;

    printf("dimmi il nome del file\n");
    scanf("%s",name);
    fp=fopen(name,"r");
    if(fp==NULL){
        printf("error");
       exit(1);
    }

printf("dimmi la lunghezza della sottostringa\n");
scanf("%d",&n);

fscanf(fp,"%d",&num);

while (fscanf(fp,"%s",S)!=EOF){
  res+=conta( S ,n);

 i++;
}





     fclose(fp);
     printf("numero=%d",res);
    return 0;
}

int conta(char S[N+1], int n){

   int f=0;
    int counter=0;
    int pos=0;
    int dim=0;
    dim=strlen(S);
    
    pos=n;

for(int k=0;k<=dim-pos && k<dim;k++){



    for(int j=k;j<n && j<dim;j++){
        switch (S[j]){
             case 'i':
            case 'a':
            case 'o':
            case 'e':
            case 'u':

            f++;

        }

    }
    if(f==2){
        counter++;
    }

    f=0;


    n++;

}
return counter;
}
