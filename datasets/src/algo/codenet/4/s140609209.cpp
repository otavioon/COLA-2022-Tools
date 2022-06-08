#define _GLIBCXX_DEBUG
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
typedef long long ll;
#define ALL(v) (v).begin(), (v).end()

int ans[10];
int id = 0;
vector<bool> D(10, false);

int func(int N) {
		while (N > 0) {
				int digit = N % 10;
				if (D[digit] == true) {
						for (int i = 0; i < 10; i++) {
								if (N / 10 == 0 && i == 0) continue;
								if (D[i] == false) {
										ans[id] = i;
										break;
								}
						}
				} else {
						ans[id] = digit;
				}

				N /= 10;
				id++;
		}
}

int main() {
		int N, K;
		cin >> N >> K;
		for (int i = 0; i < K; i++) {
				int t;
				cin >> t;
				D[t] = true;
		}

		func(N);

		for (int i = id-1; i >= 0; i--) {
				cout << ans[i];
		}

		cout << endl;
		return 0;
}
