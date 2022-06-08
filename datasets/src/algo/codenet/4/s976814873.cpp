#include "bits/stdc++.h"
using namespace std;
set<int>S;

bool f(int n) {
	while (n >0) {
		int num = n % 10;
		n /= 10;
		if (S.count(num) == 1) {
			return false;
		}
	}
	return true;
}

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0;i<K;++i) {
		int num;
		cin >> num;
		S.insert(num);
	}
	while (true) {
		if (f(N)) {
			break;
		}
		N++;
	}
	cout << N <<endl;
	return 0;
}