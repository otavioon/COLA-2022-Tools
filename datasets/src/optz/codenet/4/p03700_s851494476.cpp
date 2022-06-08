#include<stdio.h>
int main(void) {


	int n, a, b, c = 0, d = 0, i, j, k = 0, h[100000], max = 0;

	scanf("%d %d %d", &n, &a, &b);

	for (i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}

	for (j = 0; j < 1000000000; j++) {
		max = 0; d = 0;
		for (i = 0; i < n; i++) {
			if (h[i] > max) {
				max = h[i];
				k = i;
			}
		}
		for (i = 0; i < n; i++) {
			if (h[i] == h[k]) {
				h[i] -= a;
				if (h[i] <= 0) {
					d++;
				}
			}
			else {
				h[i] -= b;
				if (h[i] <= 0) {
					d++;
				}
			}
		}
		c++;
		if (d == n) {
			break;
		}
	}

	printf("%d\n", c);

	return 0;
}