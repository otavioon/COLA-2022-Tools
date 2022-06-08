#include <stdio.h>

int main() {
  int x[3000][2], i, j, a;

  for(i=0;i<3000;i++) {
    scanf("%d %d",&x[i][0], &x[i][1]);
    if(x[i][0]==0 && x[i][1]==0) break;
  }

  for(i=0;i<3000;i++) {
    if(x[i][0]==0 && x[i][1]==0) break;
    if(x[i][0]>x[i][1]){
      a = x[i][0];
      x[i][0] = x[i][1];
      x[i][1] = a;
    }
    printf("%d %d\n", x[i][0], x[i][1]);
  }

  return 0;
}

