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

//ソート済み配列a[]からn以上のなるべく小さい値を返す番号を得る
int sorted_find_inf(value_type a[], value_type n, int left, int right)
{
	if (left + 1 < right) {
		int center = left + (right - left) / 2;
		if (a[center] >= n) {
			sorted_find_inf(a, n, left, center);
		}
		else {
			sorted_find_inf(a, n, center, right);
		}
	}
	else {
		if (a[left] >= n) {
			return left;
		}
		else if(a[right] >= n){
			return right;
		}
		else {
			return right + 1;
		}
	}
}

//ソート済み配列a[]からn以下のなるべく大きい値を返す番号を得る
int sorted_find_sup(value_type a[], value_type n, int left, int right) {
	if (left + 1 < right) {
		int center = left + (right - left) / 2;
		if (a[center] > n) {
			sorted_find_sup(a, n, left, center);
		}
		else {
			sorted_find_sup(a, n, center, right);
		}
	}
	else {
		if (a[right] <= n) {
			return right;
		}
		else if(a[left] <= n) {
			return left;
		}
		else {
			return left - 1;
		}
	}
}

int main() {
	long n, a[10000], b[10000], c[10000];
	long long sum = 0;
	int i;
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
		sum += (n - sorted_find_inf(c, b[i]+1, 0, n - 1)) * (sorted_find_sup(a, b[i]-1, 0, n - 1) + 1);
	}
	printf("%lld", sum);
	return 0;
}
