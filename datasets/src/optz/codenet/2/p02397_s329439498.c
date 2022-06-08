#include<stdio.h>

int main(void) {

	int a[10002], b[10002], n=0, c;

	do {
		n += 2;
		scanf("%d %d", &a[n], &a[n+1]);
		if (a[n] <= a[n+1])
		{
			b[n] = a[n], b[n + 1] = a[n + 1];
		}
		else if(a[n] >= a[n + 1])
		{
			b[n + 1] = a[n], b[n] = a[n + 1];
		}


	} while ((a[n] != 0) || (a[n+1] != 0));
	c = n;
	for (n = 2; n <= (c - 2); n += 2)
	{
		printf("%d %d\n", b[n], b[n + 1]);
	}

	return 0;
}