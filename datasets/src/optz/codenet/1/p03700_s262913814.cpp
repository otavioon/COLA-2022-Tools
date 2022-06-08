#include"stdio.h"
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	if (*(long*)a > *(long*)b){
		return -1;
	}
	else if (*(long*)a == *(long*)b) {
		return 0;
	}
	return 1;
}
int main()
{
	long  N, A, B;
	long  i, j;
	long* h;
	long x, sum = 0;
	long hantei = 0;//残っている敵の数
	scanf("%ld %ld %ld", &N, &A, &B);
	h = (long*)malloc(N);

	for (i = 0; i < N; i++) {
		scanf("%ld", &(h[i]));
	}
	while (hantei > 0) {
		qsort(h, N, sizeof(long), cmp);
		h[i] = h[i] - A;
		if (h[i] < 1) { i++; }
		hantei = 0;
		for (j = i + 1; j < N; j++) {
			h[j] -= B;//周囲の敵へのダメージ
			if (h[j] > 0) { hantei++; }
		}
		sum++;
	}
	printf("%ld\n", sum);
	free(h);
	return 0;

}

