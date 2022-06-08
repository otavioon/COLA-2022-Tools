#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

set<int>s;
bool digit(int n) {
	while (9 < n) {
		if (s.count(n % 10))return false;
		n /= 10;
	}
	if (s.count(n))return false;
	return true;
}

int main() {
	int n, k, d,ans=0;
	cin >> n >> k;
	rep(i, n) {
		cin >> d;
		s.insert(d);
	}
	for (int i = n; i <= i * 10; i++) {
		if (digit(i)) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}

