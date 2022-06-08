#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
int a;
int c;
int i;
int max;
int min;
int sum=0;

  scanf("%d",&c);
for(i=1;i<=c;i++){
  scanf("%d",&a);
  if(c=1){
    max = a;
    min = a;}
  if(max < a){
    max = a;}
  if(min > a){
    min = a;}
  sum=sum+a;
}
printf("%d %d %d\n",min,max,sum);
return 0;}
