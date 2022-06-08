#include<stdio.h>

int main(){

	long int n, a[10000], i, e, c;

	scanf("%ld", &n);
	a[n] = 0;

	for (i = 0; i<n; i++){

		scanf("%ld", &a[i]);

	}

	for (i = n - 1; i >= 0; i--)
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

	printf("%ld %ld %ld\n", a[0], a[n - 1], a[n]);


	return 0;
}