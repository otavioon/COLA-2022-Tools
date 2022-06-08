#include <stdio.h>
int main(void){
  int n;
  int min;
  int max;
  long long int sum;

  scanf("%d\n",&n);
  int num[n];

  for(int i; i<n ; i++){
    scanf("%d ",&num[i]);
  }

  min = num[0];
  max = num[0];

  for(int i; i<n ; i++){
    if(num[i] < min){
      min = num[i];
    }
    if(num[i] > max){
      max = num[i];
    }
    sum = sum + num[i];
  }

  printf("%d %d %d\n",min,max,sum);

  return 0;
}

