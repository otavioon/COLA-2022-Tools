#include <stdio.h>

int main(){
  int x[3000], y[3000], i, n=0, tmp;

  while(1){
    scanf("%d %d", &x[n], &y[n]);
    if(x[n] == 0 && y[n] == 0)
      break;
    if(x[n] > y[n]){
      tmp = x[n];
      x[n] = y[n];
      y[n] = tmp;
    }
    n++;
  }

  for(i = 0; i < n; i++)
    printf("%d %d\n", x[i], y[i]);

  return 0;
}

