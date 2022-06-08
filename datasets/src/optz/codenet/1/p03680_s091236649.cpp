#include <iostream>
using namespace std;

int main() {
	long N, c = 0, i = 0;
	bool flg = false;
	cin >> N;
	int* a = new int[N];
	bool* b = new bool[N];
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		a[i] = t - 1;
		b[i] = false;
	}
	b[0] = true;
	while (true) {
		if (i == 1) {
			cout << c << endl;
			return 0;
		}
		if (b[a[i]]) {
			cout << -1 << endl;
			return 0;
		}
		b[a[i]] = true;
		i = a[i];
		c++;
	}
}