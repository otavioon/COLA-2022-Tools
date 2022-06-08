
#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<string>
#include<ctime>


using namespace std;

using ll = long long int;
using lln = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const double PI = acos(-1.0);
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
const long MOD = pow(10, 9) + 7;

char alfa[] = { 'A','B' ,'C','D' ,'E' ,'F' ,'G' ,'H' ,'I' ,'J' ,'K' ,'L' ,'M' ,'N' ,'O' ,'P' ,'Q' ,'R' ,'S' ,'T' ,'U' ,'V' ,'W' ,'X' ,'Y','Z' };

inline void finish() {
	cout << -1 << endl;
	exit(0);
}

unsigned GetDigit(double num) {
	return log10(num) + 1;
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

class Mod {
public:
	static inline ll Add(ll a, ll b) {
		return (a + b) % MOD;
	}

	static inline ll Sub(ll a, ll b) {
		ll ans = (a - b) % MOD;
		return (ans < 0) ? (ans + MOD) : ans;
	}

	static inline ll Mul(ll a, ll b) {
		return (a * b) % MOD;
	}

	static inline ll Div(ll a, ll b) {
		return (a % MOD) * modinv(b, MOD) % MOD;
	}
};



template <typename T>
inline void debug(vector<T> v) {
	cout << "[";
	for (ll i = 0; i < v.size() - 1; ++i) {
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1] << "]" << endl;
}

void Main();
inline void DebugMain() {
	while (true) {
		Main();
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);

	bool debug = false;
	if (debug) {
		cout << "\x1b[41m" << "Debug Mode " << endl;
	}
	(debug) ? DebugMain() : Main();
	return 0;
}

class man
{
public:
	int A;
	vector<pii> X;
	bool HeIsTrue;
private:

};

inline void Main() {
	ll X, Y, N;
	vector<ll> A;
	ll M1, D1, M2, D2;
	ll ans;
	ll sum = 0, count = 0,a =0;
	string S;
	string T;
	string Ans = "";
	int b[60];
	bool flag = false;

	cin >> N>>X;

	Yes(X < N * 500);
}

