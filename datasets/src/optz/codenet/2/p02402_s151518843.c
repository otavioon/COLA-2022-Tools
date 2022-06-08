#include<stdio.h>
int main(void)
{
	int max;
	int min;
	int i,n = 0;
	long long int sum = 0;
	int A[10000];
	scanf("%d",&n);
	max = A[0];
	min = A[0];
	for(i=0;i<n;i++) scanf("%d",&A[i]);
	for(i=0;i<n;i++){
		if(A[i]>max) max=A[i];
		if(A[i]<min) min=A[i];
		sum = sum + A[i];
		}		
	printf("%d %d %lld\n",min,max,sum);

	return 0;
}
