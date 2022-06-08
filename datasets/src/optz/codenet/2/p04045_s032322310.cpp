#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <stdio.h>
#include <tuple>
#include <bitset>
#include <cfloat>
#include <fstream>
#include <limits.h>
#include <list>
#include <math.h>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <utility>
#include <sstream>
#include <cassert>
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
using namespace std;
#define int long long
#define ll long long
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define P pair<ll, ll>
#define sz(x) (ll)x.size()
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define VE vector<ll>
#define COUT(x) cout<<(x)<<endl
#define MA map<ll,ll>
#define SE set<ll>
#define PQ priority_queue<ll>
#define PQR priority_queue<ll,VE,greater<ll>>
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define EPS (1e-12)
#define pb push_back
long long MOD = 1000000007;
//const long long MOD = 998244353;
const long long INF = 1LL << 60;
const double PI = acos(-1.0);
struct mint {
	ll x; // typedef long long ll;
	mint(ll x = 0) :x((x%MOD + MOD) % MOD) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += MOD - a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator*=(const mint a) {
		(x *= a.x) %= MOD;
		return *this;
	}
	mint operator+(const mint a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint a) const {
		mint res(*this);
		return res *= a;
	}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}
	// for prime MOD
	mint inv() const {
		return pow(MOD - 2);
	}
	mint& operator/=(const mint a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint a) const {
		mint res(*this);
		return res /= a;
	}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

struct Sieve {
	int n;
	vector<int> f, primes;

	Sieve(int n = 1) :n(n), f(n + 1) {
		f[0] = f[1] = -1;
		for (ll i = 2; i <= n; ++i) {
			if (f[i]) continue;
			primes.push_back(i);
			f[i] = i;
			for (ll j = i * i; j <= n; j += i) {
				if (!f[j]) f[j] = i;
			}
		}
	}

	bool isPrime(int x) { return f[x] == x; }

	vector<int> factorList(int x) {
		vector<int> res;
		while (x != 1) {
			res.push_back(f[x]);
			x /= f[x];
		}
		return res;
	}

	vector<P> factor(int x) {
		vector<int> fl = factorList(x);
		if (fl.size() == 0) return {};
		vector<P> res(1, P(fl[0], 0));
		for (int p : fl) {
			if (res.back().first == p) {
				res.back().second++;
			}
			else {
				res.emplace_back(p, 1);
			}
		}
		return res;
	}
};
template<class t> t gcd(t a, t b) { return b != 0 ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
bool prime(ll n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n%i == 0)return false;
	}
	return n != 1;
}
map<ll, ll> prime_factor(ll n) {
	map<ll, ll> ret;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}
ll modinv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
vector<pair<char, int>> RunLength(string s) {
	if (s.size() == 0)return {};
	vector<pair<char, int>>res(1, pair<char, int>(s[0], 0));
	for (char p : s) {
		if (res.back().first == p) {
			res.back().second++;
		}
		else {
			res.emplace_back(p, 1);
		}
	}
	return res;
}
// Digit Count
int GetDigit(int num) {
	return log10(num) + 1;
}
// bit calculation[how many "1"] (= __builtin_popcount())
int bit_count(int n) {
	int cnt = 0;
	while (n > 0) {
		if (n % 2 == 1)cnt++;
		n /= 2;
	}
	return cnt;
}
vector<long long> enum_divisors(long long N) {
	vector<long long> res;
	for (long long i = 1; i * i <= N; ++i) {
		if (N % i == 0) {
			res.push_back(i);
			if (N / i != i) res.push_back(N / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}
const ll dx[4] = { 1,0,-1,0 };
const ll dy[4] = { 0,1,0,-1 };
struct edge { ll to, cost; };
typedef long double ld;
using Graph = vector<VE>;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(20);
	//combination com(200010);
	int n, k; cin >> n >> k;
	vector<char> d(k); rep(i, k)cin >> d[i];
	for (int i = n; ; i++) {
		string tmp = to_string(i);
		bool ok = true;
		rep(j, tmp.size()) {
			rep(l, k) {
				if (tmp[j] == d[l])ok = false;
			}
		}
		if (ok) {
			cout << i << endl; return 0;
		}
	}
	return 0;
}
