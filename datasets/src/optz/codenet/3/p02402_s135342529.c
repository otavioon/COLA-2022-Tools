#include <stdio.h>

int main(void) {
	int n, i, ai, max, min, sum;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &ai);
		if (i==0) {
			max = ai;
			min = ai;
			sum = ai;
			continue;
		}
		if (max < ai) {
			max = ai;
		}
		if (min > ai) {
			min = ai;
		}
		sum += ai;
	}
	printf("%d %d %d\n", min, max, sum);
	return 0;
}