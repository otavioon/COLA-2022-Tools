#include <stdio.h>
#include <stdlib.h>
int main(){
 int n,i,g,max,min,j,a;
 int *s;
 scanf("%d",&n);
 s=(int*)malloc(sizeof(int)*n);
 i=0;max=-1000001;min=1000001;g=0;
 while(i<n){
  scanf("%d",&j);
  s[i]=j;}
 for(i=0;i<n;i++){
  a=s[i];
  if(max<=a)
   max=a;
  if(min>=a)
   min=a;
  g+=a;}
 printf("%d%d%d\n",min,max,g);
}
