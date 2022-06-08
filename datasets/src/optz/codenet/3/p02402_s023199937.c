#include<stdio.h>
int main(void){
int ai,n,i,min,max;
long sum;
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&ai);
if(i==0){
min=ai;
max=ai;
sum=ai;}
else{
sum=sum+ai;
if(min>ai){
min=ai;}
if(max<ai){
max=ai;}}}
printf("%d %d %d\n",min,max,sum);
return 0;
}