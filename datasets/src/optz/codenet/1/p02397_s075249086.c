#include<stdio.h>

int main()
{
	int num[3000][2];
	int z=0,x=0,y=0;
	int a=0;
	do
	{
		for(x = 0;x<2;x++)
		{
			scanf("%d",&num[y][x]);
		}
		
		if(num[y][0] > num[y][1])
		{
			z = num[y][0];
			num[y][0] = num[y][1];
			num[y][1] = z;
		}
		
		y++;
	}while(num[y-1][0] != 0 && num[y-1][1] != 0);
	do
	{
		printf("%d %d\n",num[a][0],num[a][1]);
		a++;
	}while(num[a][0] != 0 && num[a][1] != 0);
	
	return 0;
}