#include <stdio.h>
int a[3000], b[3000];
int h[3000], j[3000];
int main(void) {
	int e;
	for (e = 1; e < 3000; e++) {
		h[e] = j[e] = 0;
		a[e] = b[e] = 0;
	}
	int i = 1;
	int k = 1;
	while (1) {
		scanf_s("%d%d", &a[i], &b[i]);
		if (a[i] == 0 && b[i] == 0) break;
		if (a[i] <= b[i]) {
			h[i] = a[i];
			j[i] = b[i];
		}
		else {
			j[i] = a[i];
			h[i] = b[i];
		}
		i++;
	}
	while (k <= i) {
		printf("%d %d\n", h[k], j[k]);
		k++;
	}
	return 0;
}