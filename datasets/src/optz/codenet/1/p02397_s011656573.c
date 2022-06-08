#include<stdio.h>
int main() {
	int x, y, i;
	scanf("%d", &x);
	scanf("%d", &y);

	for (i = 0; i++; i <= 3000)
		if (x == 0 && y == 0)break;
	if (x < y) {
		printf("%d %d\n", x, y);
	}
	if (x > y) {
		printf("%d %d\n");
	}
	if (x == y) {
		printf("%d %d\n", x, y);
	}

	return 0;
}
