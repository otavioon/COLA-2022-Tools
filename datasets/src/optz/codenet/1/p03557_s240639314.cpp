#include<stdio.h>

int main(void){
  int N,i,j,k;
  scanf("%d",&N);
  long A[N];
  long B[N];
  long C[N];
  int cnt=0;

  for(i=0; i<N; i++){
    scanf("%lu", &A[i]);
  }
  for(i=0; i<N; i++){
    scanf("%lu", &B[i]);
  }
  for(i=0; i<N; i++){
    scanf("%lu", &C[i]);
  }
  
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      if(A[i]<B[j]){
        for(k=0; k<N; k++){
           if(B[j]<C[k]){
              cnt += 1;
              }
          }
        }else{
          continue;
        }
      }
    }
  
  printf("%d\n",cnt);

  return 0;
}
