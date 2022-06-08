#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const double EPS = 1e-10;
typedef pair<int, int> P;

int main() {
	int N;
	cin >> N;
	multiset<int> ms;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		ms.insert(A);
	}
	int ans = 0;
	while (!ms.empty()) {
		int x = *(--ms.end());
		ms.erase(x);
		int y = -1;
		for (int i = 1; i <= 30; i++) {
			if ((1<< i) <= x) continue;
			auto itr = ms.find((1 << i) - x);
			if (itr != ms.end()) {
				y = *itr;
				break;
			}
 		}
		if (y != -1) {
			ans++;
			ms.erase(y);
		}
	}
	cout << ans << endl;
}