#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	vector<int> A(N); rep(i, 0, N) {
		cin >> A[i];
	}

	sort(all(A));

	int ans = 0;

	vector<bool> used(N);
	rrep(i, 0, N) {
		int k = 0;
		int x = A[i];
		while (x) {
			k++;
			x /= 2;
		}
		int p = (1 << k) - A[i];

		int l = lower_bound(all(A), p) - A.begin();

		rep(j, l, i) {
			if (A[j] != p)break;
			if (i == j)continue;
			if (used[j])continue;
			used[i] = true;
			used[j] = true;
			ans++;
			break;
		}
	}
	cout << ans << endl;

	return 0;
}