#include<stdio.h>

int main(){
int n,min,max,sum=0;
int a[n];
int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	min=a[0];
	max=a[0];
	for(i=0;i<n;i++){
		sum=sum+a[i];
		if(a[i]<min)
		min=a[i];
		if(a[i]>max)
		max=a[i];
	}
	printf("%d %d %d\n",min,max,sum);
return 0;
}