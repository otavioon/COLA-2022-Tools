#include <stdio.h>

int main(void) {
	int n,i,max=0,min=100,sum=0;

	int a[n];

	scanf("%d",&n);

	putchar('\n');

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
		sum=sum+a[i];
	}
 	printf("%d %d %d\n",min,max,sum);
	return 0;
}
