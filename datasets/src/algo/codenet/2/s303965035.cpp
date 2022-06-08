#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
int main() {
	int n;
	scanf("%d", &n);
	multiset<int> S;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		S.insert(a);
	}
	int ans = 0;
	while (!S.empty()) {
		int x = *S.rbegin();
		S.erase(S.find(x));
		int t = 32 - __builtin_clz(x);
		int sum = 1 << t;
		int y = sum - x;
		auto it = S.find(y);
		if (it == S.end()) continue;
		S.erase(it);
		++ans;
	}
	printf("%d\n", ans);
}
