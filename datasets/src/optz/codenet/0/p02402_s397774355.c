#include <stdio.h>
int main(){
	int i,j,n, a[10000],min,max,sum=0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	min = a[0];
	max = a[0];
	for ( i = 0; i < n; i++)
	{
		for ( j =i+1 ; j < n; j++)
		{	
			if (min>a[j])
			{
				min = a[j];
			}
			if (max<a[j])
			{
				max = a[j];
			}
		}
		sum = sum + a[i];

	}
	printf("%d %d %d\n", min, max, sum);
	return 0;
}