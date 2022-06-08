// In The Name Of God

#include <bits/stdc++.h>

#define sqr(A) ((A) * (A))
#define X first
#define Y second
#define MP make_pair
#define bsz  __builtin_popcount
#define all(A) A.begin(), A.end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int PR = 727;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;

const int N = 1e5 + 20;
int a[N], n, ans;
multiset<int> s;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], s.insert(a[i]);
	while (s.size() > 1) {
		auto it = s.end(); it--;
		ll x = *it, pw = 1;
		s.erase(it);
		while (pw <= x) pw *= 2LL;
		auto f = s.find(pw - x);
		if (f != s.end()) {
			s.erase(f);
			ans++;
		}
	}
	cout << ans << endl;
}

