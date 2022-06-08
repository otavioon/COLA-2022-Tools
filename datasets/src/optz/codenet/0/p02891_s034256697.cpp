#include <bits/stdc++.h>
using namespace std;
#define debug(...) { printf("#  "); printf(__VA_ARGS__); puts(""); }
#define fi first
#define se second
#define endl "\n" 
using ll = long long;
using ull = unsigned long long; 
using pII = pair <int, int>;
using pLL = pair <ll, ll>;
using VI = vector <int>;
using VL = vector <ll>;
constexpr int mod = 1e9 + 7;
template <class T1, class T2> inline void chadd(T1 &x, T2 y) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod; } 
template <class T1, class T2> inline void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template <class T1, class T2> inline void chmin(T1 &x, T2 y) { if (x > y) x = y; }
inline int rd() { int x; cin >> x; return x; }
template <class T> inline void rd(T &x) { cin >> x; }
template <class T> inline void rd(vector <T> &vec) { for (auto &it : vec) cin >> it; }
template <class T> inline void pt(T s) { cout << s << "\n"; }
template <class T> inline void pt(vector <T> &vec) { for (auto &it : vec) cout << it << " "; cout << endl; } 
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll qpow(ll base, ll n) { ll res = 1; while (n) { if (n & 1) res = res * base % mod; base = base * base % mod; n >>= 1; } return res; }
constexpr int N = 1e2 + 10;
int n, k; char s[N]; int f[N][2], g[N][2]; 
// 0 origin
// 1 change
void run() {
	n = strlen(s + 1);
	if (n == 1) return pt(k / 2);
	f[1][0] = 0; f[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		f[i][0] = f[i - 1][1];
		if (s[i] != s[i - 1]) chmin(f[i][0], f[i - 1][0]);
		f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
	}
	if (s[1] != s[n]) pt(1ll * min(f[n][0], f[n][1]) * k);
	else {
		ll res = 1ll * f[n][1] * (k - 1) + min(f[n][0], f[n][1]);
		g[2][0] = 0, g[2][1] = 1; 
		for (int i = 3; i <= n; ++i) {
			g[i][0] = g[i - 1][1];
			if (s[i] != s[i - 1]) chmin(g[i][0], g[i - 1][0]);
			g[i][1] = min(g[i - 1][0], g[i - 1][1]) + 1;
		}
		chmin(res, min(f[n][0], f[n][1]) + 1ll * (min(g[n][0], g[n][1]) + 1) * (k - 1));	
	//	chmin(res, 1ll * (f[n][1] + min(f[n][0], f[n][1])) * (k / 2) + (k % 2 ? min(f[n][0], f[n][1]) : 0));
	//	chmin(res, 1ll * (min(g[n][0], g[n][1]) + 1 + min(f[n][0], f[n][1])) * (k / 2) + (k % 2 ? min(g[n][0], g[n][1]) + 1 : 0));
		chmin(res, 1ll * (g[n][1] + 1) * (k / 2) + 1ll * (k - k / 2) * min(f[n][0], f[n][1]));
		pt(res);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout << fixed << setprecision(20);
	while (cin >> (s + 1) >> k) run();
	return 0;
}
