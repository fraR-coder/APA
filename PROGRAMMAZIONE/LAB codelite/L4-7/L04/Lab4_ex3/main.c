#include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include <ctype.h>


int regexplen(char * regexp);
int cercaMetacarattere(char cmd,char s,char * regexp,int *pos,int l1);
char *cercaRegexp(char *src, char *regexp);
int main()
{
    char  *src= "ertyArgnRodvhjnm";
    char *regexp="A[^f]\\anR.d";
    char * f;

   int l2;
   
   l2=regexplen(regexp); 
        
        
        f= cercaRegexp(src, regexp);
         
    
    if(f!= NULL){
    printf("trovato \n");
    for(int i=0;i<l2;i++){
        printf("%c",f[i]);
    }
    printf("\n");
    }
    else{
         printf("non trovato\n");
    }


	return 0;
}

int regexplen(char * regexp){
    int l=0;
    while(*regexp!='\0'){
    
        if(*regexp=='['){
               
             while(*regexp!=']' ){
                 regexp++;
        }
       
    }
   if(*regexp=='\\'){
       l--;
    
}

    l++;
    regexp++;
    }

return l;
}


char *cercaRegexp(char *src, char *regexp){
    
   
     int i,j;
     char cmd;
 
     int pos=0;
  
    int l1= strlen(src);

     char* res;
     
     
     
  for(j=0;j<l1;j++){
      i=0;
    res=&src[j];
      
     for(pos=0;regexp[pos]!='\0' && i!=-1;pos++){
         
         cmd=regexp[pos];
        
       if(cercaMetacarattere(cmd,src[j],regexp,&pos,l1)){
          
           j++;
        
       }
       else{
           i=-1;
       }
        
     }   
         if(i!=-1){
             return res;
         }
     }
     
    
   
    
    return  NULL;
}



int cercaMetacarattere(char cmd,char s,char * regexp,int *pos,int l1){
    
    int found=0;
   

    
    switch(cmd){
        case '.' :
            found=1;
            
            break;
            
        case '[':
      
          *pos=*pos +1;
       
       
        if(regexp[*pos]!='^'){
            
            while(regexp[*pos]!=']' ){
              if(s==regexp[*pos]){
                  found=1;
                *pos=*pos +1;
              }
              else{
              
               *pos=*pos +1;
              }
            
            }           
         
        }
        else{
            found=1;
            
            *pos=*pos +1;
            while(regexp[*pos]!=']' ){
                  if(s==regexp[*pos]){
                  found=0;
                *pos=*pos +1;
              }
              else{
                    
              *pos=*pos +1;
              }
            }
        }
           
           break;
        
        case '\\':
            
           
          *pos=*pos +1;
            if(regexp[*pos]=='a'){
                
                if(islower(s)){
                    found=1;
                }
            }
            else if(regexp[*pos]=='A'){
                      if(isupper(s)){
                    found=1;
                }
                }
                              
            break;
            
            
            default:
               
               if(cmd==s){
                   found=1;
               }
               break;
         
                
        
            
    }
    return found;
}

