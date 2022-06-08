#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	int K, N;
	cin >> N >> K;
	vector<int> D(K);
	for (int i = 0; i < K; i++) {
		cin >> D[i];
	}
	for (int x = N; x < 100000; x++) {
		set<int> s;
		int tmp = x;
		while (tmp != 0) {
			s.insert(tmp % 10);
			tmp = tmp / 10;
		}
		bool flag = true;
		for (int i = 0; i < K; i++) {
			if (s.count(D[i]) != 0) {
				flag = false;
			}
		}
		if (flag) {
			cout << x;
			break;
		}
	}
	return 0;
}