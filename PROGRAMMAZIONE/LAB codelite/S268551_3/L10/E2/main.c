#include<stdlib.h>
#include<stdio.h>

#include <assert.h>
#define N 4
#define NOMEFILE "very_easy_test_set.txt"


int fZ(int ****Z, int ****R, int ****T, int ****S, int z, int r, int t, int s);
int fR(int ****Z, int ****R, int ****T, int ****S, int z, int r, int t, int s);
int fT(int ****Z, int ****R, int ****T, int ****S, int z, int r, int t, int s);
int fS(int ****Z, int ****R, int ****T, int ****S, int z, int r, int t, int s);

int max (int a, int b) {
  if (a > b)
    return a;
  return b;
}

int ****alloca4d(int *mark) {
  int i, j, k, l;
  int ****m;
  m= malloc((1+mark[0]) * sizeof(int***));
  for(i=0;i<=mark[0];i++) {
    m[i] = malloc((1+mark[1]) * sizeof(int**));
    for(j=0;j<=mark[1];j++) {
      m[i][j] = malloc((1+mark[2]) * sizeof(int*));
      for(k=0;k<=mark[2];k++) {
        m[i][j][k] = malloc((1+mark[3]) * sizeof(int));
        for(l=0;l<=mark[3];l++) {
         m[i][j][k][l] = -1;
        }
      }
    }
  }
  return m;
}



int fZ(int ****Z, int ****R, int ****T, int ****S, int z, int r, int t, int s) {
  int nextZ, nextR;
  if (z <= 0) return 0;

  if (Z[z][r][t][s] != -1) return Z[z][r][t][s];  //se trovo una collana che inizia ha una Z e dopo un numero di gemme uguali a z,r,s,t allora ho già salvato qui quanto vale
  
  nextZ = fZ(Z,R,T,S,z-1,r,t,s); //aggiungo zaffiro 
  nextR = fR(Z,R,T,S,z-1,r,t,s); // aggiungo rubino
  
  Z[z][r][t][s] = 1+max(nextZ,nextR); // calcolo il valore della lunghezza raggiunta da Z
  
  return Z[z][r][t][s];
}

int fR(int ****Z, int ****R, int ****T, int ****S, int z, int r, int t, int s) {
  int nextS, nextT;
  if (r <= 0) return 0;
  if (R[z][r][t][s] != -1) return R[z][r][t][s];

  nextS = fS(Z,R,T,S,z,r-1,t,s);
  nextT = fT(Z,R,T,S,z,r-1,t,s);
  
  R[z][r][t][s] = 1+max(nextS,nextT);
  return R[z][r][t][s];
}

int fT(int ****Z, int ****R, int ****T, int ****S, int z, int r, int t, int s) {
  int nextZ, nextR;
  if (t <= 0) return 0;
  if (T[z][r][t][s] != -1) return T[z][r][t][s];
  nextZ = fZ(Z,R,T,S,z,r,t-1,s);
  nextR = fR(Z,R,T,S,z,r,t-1,s);
  
  T[z][r][t][s] = 1+max(nextZ,nextR);
  
  return T[z][r][t][s];
}

int fS(int ****Z, int ****R, int ****T, int ****S, int z, int r, int t, int s) {
  int nextS, nextT;
  if (s <= 0) return 0;
  if (S[z][r][t][s] != -1)  return S[z][r][t][s];
  
  nextS = fS(Z,R,T,S,z,r,t,s-1);
  nextT = fT(Z,R,T,S,z,r,t,s-1);
  S[z][r][t][s] = 1+max(nextS,nextT);
  return S[z][r][t][s];
}



void cercaMax(int *mark, int maxlun) {
  int maxZ, maxR, maxT, maxS;
  int ****Z, ****R, ****S, ****T;


  int res, z=mark[0], r=mark[1], t=mark[2], s=mark[3];



  Z = alloca4d(mark);
  R = alloca4d(mark);
  T = alloca4d(mark);
  S = alloca4d(mark);
  





  maxZ = fZ(Z, R, T, S, z, r, t, s);
  if(maxZ==maxlun) {
      printf("Collana massima di lunghezza %d\n", maxlun);
      return;
  }
  maxR = fR(Z, R, T, S, z, r, t, s);
    if(maxR==maxlun) {
            printf("Collana massima di lunghezza %d\n", maxlun);
      return;
  }
    
  maxT = fT(Z, R, T, S, z, r, t, s);
    if(maxT==maxlun){
    printf("Collana massima di lunghezza %d\n", maxlun);
      return;
  }
  maxS = fS(Z, R, T, S, z, r, t, s);
    if(maxS==maxlun){
    printf("Collana massima di lunghezza %d\n", maxlun);
      return;
  }

  res = max(maxZ, max(maxR, max(maxT, maxS)));
  
  printf("Collana massima di lunghezza %d\n", res);
}

int main(){
  int  i, j;
  int  mark[N];
  int n_tot=0;
  int R;
  char val[N]={'Z','R','T','S'};
   FILE *fp;
    fp=fopen(NOMEFILE,"r");
    assert(fp!=NULL);

   fscanf(fp,"%d",&R);
    for(i=0;i<R;i++){
        n_tot=0;
        
        printf("test numero %d\n",i+1);
        for(j=0;j<N;j++){
            fscanf(fp,"%d",&mark[j]);
            n_tot+=mark[j];
        }
 
    
    cercaMax(mark,n_tot);

  }
  fclose(fp);
  return 0;
}
