#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
#define reps(i, S, E) for (ll i = (S); i <= (E); i++)
#define rep(i, N) reps(i, 0, N-1)
#define deps(i, E, S) for (ll i = (E); i >= (S); i--)
#define dep(i, N) deps(i, N-1, 0)
const ll INF = 1LL << 60;
const int INF_INT = 1 << 30;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
struct mll {
	static ll MOD;
	ll val;
	mll(ll v = 0) : val(v % MOD) { if (val < 0) val += MOD; }
	mll operator - () const { return -val; }
	mll operator + (const mll &b) const { return val + b.val; }
	mll operator - (const mll &b) const { return val - b.val; }
	mll operator * (const mll &b) const { return val * b.val; }
	mll operator / (const mll &b) const { return mll(*this) /= b; }
	mll operator + (ll b) const { return *this + mll(b); }
	mll operator - (ll b) const { return *this - mll(b); }
	mll operator * (ll b) const { return *this * mll(b); }
	friend mll operator + (ll a, const mll &b) { return b + a; }
	friend mll operator - (ll a, const mll &b) { return -b + a; }
	friend mll operator * (ll a, const mll &b) { return b * a; }
	mll &operator += (const mll &b) { val = (val + b.val) % MOD; return *this; }
	mll &operator -= (const mll &b) { val = (val + MOD - b.val) % MOD; return *this; }
	mll &operator *= (const mll &b) { val = (val*b.val) % MOD; return *this; }
	mll &operator /= (const mll &b) {
		ll c = b.val, d = MOD, u = 1, v = 0;
		while (d) {
			ll t = c / d;
			c -= t * d; swap(c, d);
			u -= t * v; swap(u, v);
		}
		val = val * u % MOD;
		if (val < 0) val += MOD;
		return *this;
	}
	mll &operator += (ll b) { return *this += mll(b); }
	mll &operator -= (ll b) { return *this -= mll(b); }
	mll &operator *= (ll b) { return *this *= mll(b); }
	mll &operator /= (ll b) { return *this /= mll(b); }
	bool operator == (const mll &b) { return val == b.val; }
	bool operator != (const mll &b) { return val != b.val; }
	bool operator == (ll b) { return *this == mll(b); }
	bool operator != (ll b) { return *this != mll(b); }
	friend bool operator == (ll a, const mll &b) { return mll(a) == b.val; }
	friend bool operator != (ll a, const mll &b) { return mll(a) != b.val; }
	friend ostream &operator << (ostream &os, const mll &a) { return os << a.val; }
	friend istream &operator >> (istream &is, mll &a) { return is >> a.val; }
	static mll Combination(ll a, ll b) {
		chmin(b, a - b);
		if (b < 0) return mll(0);
		mll c = 1;
		rep(i, b) c *= a - i;
		rep(i, b) c /= i + 1;
		return c;
	}
};
using vmll = std::vector<mll>;
using vvmll = std::vector<vmll>;
using vvvmll = std::vector<vvmll>;
using vvvvmll = std::vector<vvvmll>;

struct Fast {
	Fast() {
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast; //cin,cout高速化のおまじない＋桁数指定

ll mll::MOD = (ll)(1e9 + 7);// 998244353ll;


int main() {
	vvll c(3, vll(3));
	rep(j, 3) rep(i, 3){
		cin >> c[j][i];
	}

	vll minRow(3);
	rep(i, 3) {
		minRow[i] = min(c[i][0], min(c[i][1], c[i][2]));
	}

	bool result = false;

	reps(j0, 0, minRow[0]) {
		reps(j1, 0, minRow[1]) {
			reps(j2, 0, minRow[2]) {
				if (c[0][0] - j0 != c[1][0] - j1 || c[0][0] - j0 != c[2][0] - j2) {
					continue;
				}

				if (c[0][1] - j0 != c[1][1] - j1 || c[0][1] - j0 != c[2][1] - j2) {
					continue;
				}

				if (c[0][2] - j0 != c[1][2] - j1 || c[0][2] - j0 != c[2][2] - j2) {
					continue;
				}

				result = true;
			}
		}
	}

	if (result == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
