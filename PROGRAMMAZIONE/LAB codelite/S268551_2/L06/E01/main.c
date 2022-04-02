#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define L 255
typedef struct {
    int n;
    char **song;
}Tab;



int leggi_file(Tab **playlist);
int genera_playlist(Tab *playlist, char *sol[], int pos,int count,int A );

int main()
{
    Tab *playlist;
   int A;
    int i,j;
  
    int pos=0;
    int count=0;
     
  A=  leggi_file(&playlist);

// char *sol= (char*)malloc(A*sizeof(char));
char *sol[A];
count=genera_playlist(playlist,sol,pos,count,A);


for(int i=0;i<A;i++){
    for(int j=0;j<playlist[i].n;j++){
         free(playlist[i].song[j]);
    }
        
    free(playlist[i].song);
}
free(playlist);


printf(" il numero di possibili playlist : %d\n",count);

         

    
    
    return 0;
}


int leggi_file(Tab **playlist){
    
    int A;
    int i,j,l;
  Tab *s;
  char tmp[L];
  char tmp1[L];
    
    
    FILE * fp;
    fp=fopen("brani.txt","r");
    if (fp==NULL) exit(1);
    
    fscanf(fp,"%d",&A);
   
s=(Tab*)malloc(A*sizeof(Tab));
    
 
    
        for( i=0;i<A;i++){
    
        fscanf(fp,"%d",&s[i].n);   
         
      
      s[i].song=(char **)malloc(s[i].n*sizeof(char*));  
        for(j=0;j<s[i].n;j++){
          fscanf(fp,"%s",tmp);
           l=strlen(tmp)+1;
           
           
            
            s[i].song[j]=(char*)malloc(l*sizeof(char));
            
            strcpy(s[i].song[j],tmp);
          
            
        /*
        s[i].song[j]=(char *)malloc(L *sizeof(char));
         
        fscanf(fp,"%s",s[i].song[j]);*/
        
        }
        }        
*playlist=s;
fclose(fp);


return A;
    
}

int genera_playlist(Tab *playlist, char *sol[], int pos,int count, int A ){
    int i=0;
    int l;
    if(pos>=A){
        for( i=0;i<A;i++){
        printf("%s\n",sol[i]);
        }
        printf("-------------------\n");
        return count+1;
            
        }
        
    for( i=0;i<playlist[pos].n;i++){
        l=strlen(playlist[pos].song[i])+1;
        sol[pos]=(char *)malloc(l *sizeof(char));
        strcpy(sol[pos],playlist[pos].song[i]);
        count =genera_playlist(playlist,sol,pos+1,count,A);
      free(sol[pos]);
        
        
    }
    return count;
    
    
    
}