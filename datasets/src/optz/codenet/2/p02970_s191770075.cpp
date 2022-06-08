#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<unordered_map>
#include<functional>
#include<map>
#include<iomanip>
#include<limits>
#include<unordered_set>
#include<cmath>
#include <numeric>
#include <array>
#include<utility>
#include <complex>
#define M_PI 3.141592653589793238
using namespace std;
long long p9 = 998244353;
long long p1 = 1000000007;
#define upperbound(v,val) upper_bound(v.begin(),v.end(),val)-v.begin()
#define lowerbound(v,val) lower_bound(v.begin(),v.end(),val)-v.begin()
#define int long long
#define ll long long
#define vel vector<ll>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp(a,b) make_pair(a,b)
#define pin pair<ll,ll>
#define qin pair<pin,int>
#define V vector
#define Endl endl
#define veb vector<bool>
#define fcout cout << fixed << setprecision(15)
#define rev(s) reverse(s.begin(),s.end())
#define lower(h,val) (lower_bound(h.begin(),h.end(),val)-h.begin())
#define upper(h,val) (upper_bound(h.begin(),h.end(),val)-h.begin())
#define vveb V<veb>
#define omajinai cin.tie(0);ios::sync_with_stdio(false);
#define endl "\n"
#define pb push_back
vel kai;
vel inv_kai;
vel inv;
int root(int x, vel& pa) {
	if (pa[x] == -1) { return x; }
	int ans = root(pa[x], pa); pa[x] = ans;
	return ans;
}
bool mar(int x, int y, vel& pa) {
	x = root(x, pa);
	y = root(y, pa);
	if (x != y) { pa[x] = y; }
	return (x != y);
}
int gcd(int x, int y) {
	if (x < y) { return gcd(y, x); }
	if (y == 0) { return x; }
	return gcd(y, x % y);
}
int lcm(ll x, ll y) {
	x = abs(x); y = abs(y);
	return x * (y / gcd(x, y));
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
void make_inv(int max_inv, int p) {
	inv = vel(max_inv + 1, 1);
	for (int i = 2; i <= max_inv; i++) {
		inv[i] = p - ((p / i) * inv[p % i]) % p;
	}
}
void make_kai(int max_kai, int p) {
	kai = vel(max_kai + 1, 1);
	inv_kai = kai;
	make_inv(max_kai, p);
	rep(i, max_kai) {
		kai[i + 1] = kai[i] * (i + 1); kai[i + 1] %= p;
		inv_kai[i + 1] = inv_kai[i] * inv[i + 1]; inv_kai[i + 1] %= p;
	}
}
int com(int n, int r, int p) {
	if ((n < 0) || (r < 0) || (r > n)) { return 0; }
	int ans = (kai[n] * inv_kai[r]) % p;
	return (ans * inv_kai[n - r]) % p;
}
int per(int n, int r, int p) {
	if ((n < 0) || (r < 0) || (r > n)) { return 0; }
	return (kai[n] * inv_kai[n - r]) % p;
}
vel uni(vel x) {
	if (x.size() == 0) { return x; }
	sor(x);
	int n = x.size();
	vel ans(1, x[0]);
	for (int j = 1; j < n; j++) {
		if (x[j - 1] != x[j]) { ans.push_back(x[j]); }
	}
	x = ans;
	return x;
}
vel dijk(V<V<pin>>& way, int st, int inf) {
	int n = way.size();
	vel dist(n, inf); dist[st] = 0;
	priority_queue<pin, vector<pin>, greater<pin>> pq;
	pq.push(mkp(0, st));
	veb is_checked(n, false);
	while (!pq.empty()) {
		pin x = pq.top(); pq.pop();
		int pot = x.second;
		if (!is_checked[pot]) {
			is_checked[pot] = true;
			for (auto y : way[pot]) {
				int nex_dist = x.first + y.second;
				int nex_pot = y.first;
				if (dist[nex_pot] > nex_dist) {
					dist[nex_pot] = nex_dist;
					pq.push(mkp(nex_dist, y.first));
				}
			}
		}
	}
	return dist;
}
void make_tree(vvel& chi, vel& par, int n) {
	V<V<pin>> way(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		way[a].push_back(mkp(b, 1));
		way[b].push_back(mkp(a, 1));
	}
	vel dist = dijk(way, 0, n + 1);
	par = vel(n, -1);
	chi = vvel(n);
	rep(i, n) {
		for (auto nex : way[i]) {
			int pot = nex.first;
			if (dist[pot] > dist[i]) { chi[i].push_back(pot); }
			else { par[i] = pot; }
		}
	}
}
void pri(vel& v) {
	if (v.size() == 0) { return; }
	cout << v[0];
	rep(i, v.size() - 1) { cout << " " << v[i + 1]; }
	cout << endl;
	return;
}
int modpow(int a, int n, int p) {
	if (n == 0) { return 1; }
	int m = n / 2;
	int x = modpow(a, n / 2, p);
	x *= x; x %= p;
	if (n % 2 == 1) { x *= a; x %= p; }
	return x;
}
vel dx = { 0,0,-1,1 };
vel dy = { 1,-1,0,0 };
#define ui long long
int po(int a) {
	return a * a * a * a * a;
}
bool solve(int ex, V<pin>& a, int i, vel &v) {
	if (ex == 0) {
		int sz = v.size();
		cout << sz << endl;
		rep(i, sz) {
			cout << a[v[i]].second + 1;
			if (i != sz - 1) { cout << " "; }
			else { cout << endl; }
		}
		return true;
	}
	if (i == 0) { return false; }
	auto x = lower_bound(a.begin(), a.end(), mkp(ex + 1, (int)0));
	if (x == a.begin()) { return false; }
	x--;
	int y = x - a.begin();
	mmin(y, i - 1);
	for (int nex = y; nex >= 0; nex--) {
		v.push_back(nex);
		if (solve(ex - a[nex].first, a, nex, v)) {
			return true;
		}
		v.pop_back();
	}
	return false;
}
signed main() {
	omajinai;
	int n, d; cin >> n >> d;
	cout << (n + 2 * d) / (2 * d + 1) << endl;
	return 0;
}
