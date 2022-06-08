#include <stdio.h>
int main()
{
	int a[4][4];
	int i ,j;
	int sum = 0;
	for(i = 1; i <= 3 ; i++)
	{
		for(j = 1 ; j <= 3 ; j++)
		{
			scanf("%d", &a[i][j]);
			sum = sum + a[i][j];
		}
	}
	if(sum == 3 * (a[1][1] + a[2][2] + a[3][3]))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}