//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define all(x) (x).begin(),(x).end()

#define MOD 1000000007LL
#define INF (1LL<<60LL)
#define int long long
#define MAX_N (100001)
typedef long long ll;

using namespace std;

vector<vector<int>> v(10, vector<int>(10, 0));

int modpow(int n, int a) {
	int res = 1;
	while (a > 0) {
		if (a & 1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		a >>= 1;
	}
	return res;
}

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0)return x;
	else return gcd(y, x % y);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k, x; cin >> k >> x;
	if (k * 500 >= x)cout << "Yes" << endl;
	else cout << "No" << endl;
}