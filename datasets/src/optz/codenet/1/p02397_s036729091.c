#include <stdio.h>

int main (void){
  int x[10000], y[10000];
  int i = 0;

  while(1){
    scanf("%d %d", &x[i], &y[i]);
    if(x[i] == 0 && y[i] == 0){
      break;
    }
    i++;
  }

  for(i = 0; x[i] != 0 && y[i] != 0; i++){
    printf("%d %d\n", y[i], x[i]);
  }

  return 0;
}