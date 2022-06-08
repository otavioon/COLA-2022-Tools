#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
using namespace std;
int n, j = 0, l = 0;
long long ans = 0;
int a[100010], b[100010], c[100010];
long long ac[100010] = { 0 };
long long bc[100010] = { 0 };
int main() {
	cin >> n;
	for (int a1 = 0; a1 < n; a1++) {
		cin >> a[a1];
	}
	for (int b1 = 0; b1 < n; b1++) {
		cin >> b[b1];
	}
	for (int c1 = 0; c1 < n; c1++) {
		cin >> c[c1];
	}
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	for (int i = 0; i < n; i++) {
		for (;; j++) {
			if (j == n || b[i] <= a[j]) {
				ac[i] += ac[i - 1];
				break;
			}
			else {
				ac[i]++;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		for (;; l++) {
			if (l == n || c[k] <= b[l]) {
				bc[k] += bc[k - 1];
				break;
			}
			else {
				bc[k] += ac[l];
			}
		}
	}
	for (int m = 0; m < n; m++) {
		ans += bc[m];
	}
	cout << ans << endl;
	return 0;
}