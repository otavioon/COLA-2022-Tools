#include<stdio.h>

int main(){

	int n, a[10000], i, e, c;

	scanf("%d", &n);
	a[n] = 0;

	for (i = 0; i<n; i++){

		scanf("%d", &a[i]);

	}

	for (i = n-1; i >= 0; i--)
	{
		for (c = 0; c < i; c++)
		{
			if (a[c]>a[c + 1])
			{
				e = 0;
				e = a[c];
				a[c] = a[c + 1];
				a[c + 1] = e;

			}
		}



	}

	for (i = 0; i<n; i++){
		a[n] += a[i];
	}

	printf("%d %d %d\n", a[0], a[n - 1], a[n]);


	return 0;
}