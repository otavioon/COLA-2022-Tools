#include<stdio.h>
int main(void){
int n,i,min,max;
int sum=0;
scanf("%d",&n);
int a[n];
for(i=0;i < n;i++){
scanf("%d",a[i]);
sum += a[i];
min=a[0];
max=a[0];
if (min > a[i]){
min=a[i];
}
if (max < a[i]){
max=a[i];
}
}
printf("%d %d %d\n",min,max,sum);
return 0;
}