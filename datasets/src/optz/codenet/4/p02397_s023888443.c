#include <stdio.h>

int main()
{
	int x,y;
	
	scanf("%d %d", &x, &y);
	
	while( x || y )
	{
		if( y < x )
		{
			y ^= x;
			x ^= y;
			y ^= x;
		}
		printf("%d %d\n", x, y);
		scanf("%d %d", &x, &y);
	}
	return 0;
}