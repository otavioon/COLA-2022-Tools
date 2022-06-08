#include <cstdio>
using namespace std;

typedef long value_type;

value_type med3(value_type x, value_type y, value_type z)
{
	if (x < y)
		if (y < z) return y; else if (z < x) return x; else return z; else
			if (z < y) return y; else if (x < z) return x; else return z;
}

void quicksort(value_type a[], int left, int right)
{
	if (left < right) {
		int i = left, j = right;
		value_type tmp, pivot = med3(a[i], a[i + (j - i) / 2], a[j]);
		while (1) {
			while (a[i] < pivot) i++;
			while (pivot < a[j]) j--;
			if (i >= j) break;
			tmp = a[i]; a[i] = a[j]; a[j] = tmp;
			i++; j--;
		}
		quicksort(a, left, i - 1);
		quicksort(a, j + 1, right);
	}
}

int main() {
	long n, a[10000], b[10000], c[10000], sumb[10000], sum=0;
	int i, j, k;
	scanf("%ld", &n);
	for (i = 0; i < n; i++) {
		scanf("%ld", &a[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%ld", &b[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%ld", &c[i]);
	}
	quicksort(a, 0, n - 1);
	quicksort(b, 0, n - 1);
	quicksort(c, 0, n - 1);
	for (i = 0; i < n; i++) {
		j = 0;
		while (j < n && b[i] >= c[j]) { j++; }
		sumb[i] = n-j;
	}
	for (i = 0; i < n; i++) {
		j = 0;
		while (j < n && a[i] >= b[j]) { j++; }
		for (k = j; k < n; k++) {
			sum += sumb[k];
		}
	}
	printf("%ld", sum);
	return 0;
}