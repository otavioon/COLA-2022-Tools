#include <stdio.h>

int main(void) 
{
	unsigned int n;
	int	a[n];
	int i;
	int min = 1000000;
	int max = - 1000000;
	long long sum = 0;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", a + i);
	}
	
	for(i = 0; i < n; i++)
	{
		if(min > a[i])
		{
			min = a[i];
		}
		if(max < a[i])
		{
			max = a[i];
		}
		sum += a[i];
	}
	printf("%d %d %d\n", min, max, sum);
	return 0;
}