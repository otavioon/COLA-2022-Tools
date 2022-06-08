#include <stdio.h>

#define DATA 10000

int main(void)
{
	int n, i;
	int a[DATA];
	long long int sum = 0;
	long int max = -1000000, min = 1000000;

	scanf("%d", &n);
	if(n < 1)
		return -1;
	for(i = 0;i < n;i++)
	{
		scanf("%d", &a[i]);
		if(a[i] > max)
			max = a[i];
		if(a[i] < min)
			min = a[i];
		sum += a[i];
	}
	printf("%ld %ld %ld\n", min, max, sum);

	return 0;
}