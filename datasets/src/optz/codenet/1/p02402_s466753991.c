#include<stdio.h>

int main(void)
{
	int n, x, min = 1000000, max = -1000000, i;
	long long int sum = 0;

	scanf("%d", &n);
	
	if (n == 0)
	{
		printf("0 0 0\n");
	}
	else if (n == 1)
	{
		scanf("%d", &x);
		printf("%d %d %d\n", x, x, x);
	}
	else if (n >= 2)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (x < min)
			{
				min = x;
			}
			if (x > max)
			{
				max = x;
			}
			sum = sum + x;
		}

		printf("%d %d %lld\n", min, max, sum);
	}

	return 0;
}