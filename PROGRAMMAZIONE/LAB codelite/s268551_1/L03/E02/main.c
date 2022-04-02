#include <stdio.h>
#include <stdlib.h>

int dimensione (int size, int bigEndian) ;
void stampaCodifica (void *p, int size, int bigendian);

int main()
{
    float af;
    double ad;
    long double ald;
    int test=1;
    char *p ;
    int bigendian;
    
    p = (char *)&test;
    //guardo il primo byte, se è =1 allora vuol dire che sto guardando il meno significativo
   if(*p==0){  
       bigendian=1;
        printf("Big Endian\n");
    }
   else{  
       bigendian=0;
        printf("Little Endian\n");
    }
   
	printf("le dimensioni sono \nfloat =%d\ndouble=%d\nlong double=%d\n",(int) sizeof(af),(int) sizeof(ad),(int) sizeof(ald));
    
     printf("dimmi un numero con la virgola ed eventuale esponente in base 10\n");
   scanf("%f", &af);
  ad = (double)af;
  ald = (long double)af;
  
   printf("float: \n");
   stampaCodifica((void *)&af,sizeof(af),bigendian);
      printf("double: \n");
    stampaCodifica((void *)&ad,sizeof(ad),bigendian);
       printf("long double: \n");
     stampaCodifica((void *)&ald,sizeof(ald),bigendian);
   
  
  
	return 0;
}

void stampaCodifica (void *p, int size, int bigendian){
    
    int i,j;
     unsigned char *pchar = p;
    char bits[128];
    int nbits;
    int bitexp;
    
    size = dimensione (size, bigendian);
    
     for (i=0; i<size; i++) {
        for (j=0; j<8; j++, pchar[i] /= 2) {
            bits[(i*8)+j] = pchar[i]%2; 
  }
  }
  
  nbits = size*8;
  switch (size) {
  case 4:  bitexp=8; 
    break;
  case 8: bitexp= 11;  
  break;
  default: bitexp=15; 
  break;
  }
  
   printf("bit di segno : %d\n", (int)bits[nbits-1]);
  printf("esponente    : ");
  for (i=nbits-2; i>nbits-2-bitexp; i--)
    printf("%d", (int)bits[i]);
  printf("\nmantissa     : ");
  for (i=nbits-2-bitexp; i>=0; i--)
    printf("%d", (int)bits[i]);
  printf("\n");
  }
  
    
    
int dimensione (int size, int bigEndian) {

  if (size>8 && !bigEndian) {
    int s;
   
    long double a = 1.0, b = -a;
    unsigned char *pa=(unsigned char *)&a, *pb=(unsigned char *)&b; 
  
    for (s=0; s<size && pa[s]==pb[s]; s++);
    if (s<size) {
      printf("Padding di %d byte\n", size-s-1);
      size = s+1;
      printf("Dimensioni effettive: %d\n", size);
    }
  }
  return size;
}



