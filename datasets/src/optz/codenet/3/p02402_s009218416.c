#include <stdio.h>
#define N 100000

int main(void) {
	int n,i,a[N],min=1000000,max=-1000000;
	long long int sum=0;
	scanf("%d",&n);
	if(n>0&&n<=10000){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]>=-1000000&&a[i]<=1000000){
				if(a[i]<min) min=a[i];
				if(a[i]>max) max=a[i];
				sum+=a[i];
			}
		}
		printf("%d %d %d\n",min,max,sum);	
	}
	
	
	return 0;
}

