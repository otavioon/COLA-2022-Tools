#include <stdio.h>

int main(void)
{
	int i,j,k,a,b,c[3000],d[3000];

	i=0;

	scanf("%d %d", &a, &b);

	while((a!=0) && (b!=0))
	{	
		if(a>b)
		{
			c[i]=b;
			d[i]=a;
		}
		else
		{
			c[i] = a;
			d[i] = b;
		}

		i++;
		scanf("%d %d", &a, &b);
	}

	for(k=0;k<i;k++)
	{
		printf("%d %d\n", c[k], d[k]);
	}

	return 0;
}