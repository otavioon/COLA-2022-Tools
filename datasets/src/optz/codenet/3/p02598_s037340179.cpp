#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <math.h>
#include <cmath>
#include <ctime>
#include <stdlib.h>

using namespace std;

#define int long long
#define endl "\n"
#define all(v)  v.begin(),v.end()
#define fir first
#define sec second
#define m_p make_pair
#define m_t make_tuple
#define rep(i,n)  for(int i=0; i<(int) (n); i++)


const double pai = 3.1415926535897;
const int mod = 1000000007;
const int INF = 1000000021;
const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];


//x未満の要素数を返す二分探索関数
int b_s(vector<int>& vec, int xx) {
	return lower_bound(all(vec), xx) - vec.begin();
}
template<typename T>void vecout(vector<T>& vec) { for (T t : vec) cout << t << " "; cout << endl; }
template<typename TT>void vecin(vector<TT>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}
}
template<class tt> struct counter {
	map<tt, int>mp;
	bool add(tt t, int xx) {
		if (!mp.count(t)) {
			mp[t] = xx;
			return true;
		}
		mp[t] += xx;
		if (!mp[t]) {
			mp.erase(t);
		}
		return false;
	}
};

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

//n個を1個以上のx組のグループに分ける重複組み合わせはcom(n-1,x-1)
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
long long modpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

bool chmax(int& xx, int yy) {
	if (xx < yy) {
		xx = yy;
		return true;
	}
	return false;
}
bool chmin(int& xx, int yy) {
	if (xx > yy) {
		xx = yy;
		return true;
	}
	return false;
}
int gcd(int xx, int yy) {
	int p = xx;
	int q = yy;
	if (q > p)swap(p, q);
	while (p % q != 0) {
		p %= q;
		swap(p, q);
	}
	return q;
}
int lcm(int xx, int yy) {
	return xx * yy / gcd(xx, yy);
}
bool prime(int xx) {
	if (xx <= 1) {
		return 0;
	}
	for (int i = 2; i * i <= xx; i++) {
		if (xx % i == 0) {
			return 0;
		}
	}
	return 1;
}



signed main() {
	int n, k,m=0,ans=0;
	cin >> n >> k;
	vector<int>vec(n);
	rep(i, n) {
		cin >> vec[i];
		chmax(m, vec[i]);
	}
	int a1 = 0, a2 = m + 1,a3;//長さ
	while (a1 + 1 < a2) {
		a3 = (a1 + a2) / 2;
		int t = 0;//切る回数の和
		rep(j, n) {
			t += ceil(vec[j] / (a3 + 0.0))-1;
		}
		if (t > k) {
			a1 = a3;
		}
		else {
			a2 = a3;
		}
	}
	cout << a3 << endl;
}