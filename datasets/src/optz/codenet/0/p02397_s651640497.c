#include <stdio.h>
int main (void)
{
	int x, y;

	while (scanf("%d %d", &x, &y) != EOF || x != 0 && y != 0){

		if (x != 0 || y != 0){
				if (x < y)
					printf("%d %d\n", x, y);
				else
					printf("%d %d\n", y, x);
		}
	}

	return 0;
}