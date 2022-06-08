#include <stdio.h>

int main(){
 int x[3000];
 int y[3000];
 int j = 0;
 int c = 0;
 int i;
 for(i = 0; j = 0; i++){
  scanf("%d %d\n", &x[i], &y[i]);
  if(x[i-1] ==0 && y[i-1] == 0)
   j = 1;
  else
   c++;
 }

 for(j = 0; j <= c; j++){
  if(x[j] > y[j])
   printf("%d %d\n", y[j], x[j]);
  else if(x[j] <= y[j])
   printf("%d %d\n", x[j], y[j]);
 }

 return 0;

}