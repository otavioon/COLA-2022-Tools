#include <stdio.h>
int main(void) {
	int n, min, max, compare, sum;
	min = 1000000;
	max = -1000000;
	scanf("%d", &n);
	while (scanf("%d", &compare) == 1) {
		if (n == 1) printf("%d %d %d\n", compare, compare, compare);
		else if (compare < min) min = compare;
		else if (compare > max) max = compare;
		sum += compare;
	}
	printf("%d %d %d\n", min, max, sum);
	return 0;
}