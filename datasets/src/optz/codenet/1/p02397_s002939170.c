#include <stdio.h>
#include <string.h>

int swap(int *a, int *b);
int main(void) {
	int temp,a, b,i;
	for (i = 0; i < 3000; i++) {
		scanf("%d %d\n", &a, &b);
		if (a == 0 && b == 0) break;

		swap(&a, &b);
		printf("%d %d\n", a, b);

		
	}

	return 0;
}

int swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

	return 0;
}
	