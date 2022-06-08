#include <stdio.h>
#define TATE 16000
#define YOKO 16000
int main(void){

  int x[TATE],y[YOKO],i=0,a=0;

  for(i = 0 ; i < TATE ; i++){
    scanf("%d  %d",&x[i],&y[i]);
    if(x[i] == 0 && y[i] == 0){
      break;
    }
  }

  printf("\n");
    for(i = 0 ; i < TATE ; i++){
      if(x[i] > y[i]){
      a = x[i];
      x[i] = y[i];
      y[i] = a;
    }
    printf("%d  %d\n",x[i],y[i]);
    if(x[i] == 0 && y[i] == 0){
      break;
    }
    }

    return 0;
}