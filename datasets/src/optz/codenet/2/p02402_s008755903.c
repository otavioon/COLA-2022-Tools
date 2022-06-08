#include<stdio.h>

int main(){

int n,i,m[100000];
int min,sum,max;
max=0;
min=m[0];
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&m[i]);

if(m[i]>max)max=m[i];
if(m[i]<=min)min=m[i];
sum=sum+m[i];
}
printf("%d%d%d",min,max,sum);
return 0;
}