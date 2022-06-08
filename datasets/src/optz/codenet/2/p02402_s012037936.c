#include<stdio.h>

int main(){
  long i, n, max, min, sum;
  long num[10000];
  sum = 0;

  scanf("%d", &n);

  max = num[0];
  min = num[0];

  for(i=0; i<n; i++){
    scanf("%d", &num[i]);
    sum =+ num[i];

    if(max < num[i])
      max = num[i];
    if(min > num[i])
      min = num[i];
  }

  printf("%d %d %d\n", min, max, sum);

 return 0;
}