#include <stdio.h>

int main(void){
  
  int n,i,x,sum=0;
  scanf("%d\n", &n);
  int min=1000000,max=-1000000;
  
  
  if(n>0 && n<=10000){
  for(i=0;i<n;i++){
       scanf("%d",&x);
      sum += x;
      if(x<=min) min = x;
      if(x>=max) max = x;
    
  }
  printf("%d %d %d\n",min,max,sum);
  }
  
    return 0;
}
