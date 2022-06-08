#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string.h>
#define _USE_MATH_DEFINES
#define LL long long
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int max(int *ary) {
	int max = 0;
	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++)
		if (max < ary[i]) max = ary[i];
	return max;
}

int nmax(int *ary) {
	int max = 0, num;
	for (int i = 0; i < sizeof(ary) / sizeof(ary[0]); i++)
		if (max < ary[i]) {
			max = ary[i];
			num = i;
		}
	return max, num;
}

int main() {
	int n, a[100000], now = 1;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[now - 1] == 2) {
			cout << i << endl;
			return 0;
		}
		else now = a[now - 1];
	}
	cout << -1 << endl;
	return 0;
}