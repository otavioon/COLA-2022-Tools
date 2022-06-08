#include <stdio.h>

int main()
{

	int i, n, j, tmp;
	long int sum = 0;
	long int a[n];

	scanf("%d", &n);

	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}

	for(i=0;i<n;i++){
		for(j=n-1;j>i;j--){
			if(a[i] > a[j]){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	printf("%d %d %d\n", &a[0], &a[n-1], &sum);

	return 0;
}