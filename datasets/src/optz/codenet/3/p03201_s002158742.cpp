#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>
#include <string>
using namespace std;

long long pow2(long long value) {
	int digit = 0;
	for (digit = 0; value >= (1ll << digit); digit++);
	return 1ll << digit;
}

int main(){
	long long a[200001] = {};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<long long>());
	int pair = 0;
	for (int i = 0; i < n; i++) {
		long long rest = pow2(a[i]) - a[i];
		for (int j = i + 1; j < n; j++) {
			if (rest == a[j]) {
				pair++;
				a[j] = 0;
				break;
			}
		}
	}

	cout << pair << endl;

	return 0;
}