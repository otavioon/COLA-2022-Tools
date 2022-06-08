#include <stdio.h>
int main(void){
 int a=0;
 int x=0;
 int max=0;
 int min=0;
 int sum=0;
 scanf("%d", &a);
 scanf("%d", &x);
 max=min=x;
 for(int i=1; i<a; i++){
  scanf("%d", &x);
  if(max<x){
   max=x;
  }
  if(min>x){
   min=x;
  }
  sum=sum+x;
 }
 printf("%d %d %d\n", &min, &max, &sum);
}
