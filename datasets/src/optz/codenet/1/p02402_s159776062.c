#include <stdio.h>

int main(void)
{
	int n, min = 1000000, max = -1000000, sum = 0, i;

	scanf("%d", &n);
	int a[n], out[3];

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);

		if (a[i] > max)
		{
			max = a[i];
		}

		if (a[i] < min)
		{
			min = a[i];
		}

		sum += a[i];
	}

	out[0] = min;
	out[1] = max;
	out[2] = sum;

	for (i = 0; i < 3; i++)
	{
		if (i == 2)
		{
			printf("%d?\n", out[2]);
		}
		else
		{
			printf("%d ", out[i]);
		}
	}

	return 0;
}