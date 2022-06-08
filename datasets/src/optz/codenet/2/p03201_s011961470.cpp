#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SORT(c) sort((c).begin(),(c).end())

typedef long long ll;
const ll INF = 1LL<<60;
const ll mod = 1e9 + 7;
const int MAX_N = 5e5 + 5;
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
vector<ll> prime;

ll inv[MAX_N], fac[MAX_N];

template <class T = ll> T in() { T x; cin >> x; return (x); }
inline ll GCD(ll a, ll b) { ll c; while (b != 0) { c = a % b; a = b; b = c; }return a; }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline ll POW(ll a, ll b) { ll c = 1; while (b > 0) { if (b & 1) { c = a * c%mod; }a = a * a%mod; b >>= 1LL; }return c; }
inline void _nCr() { fac[0] = 1; for (int i = 1LL; i < MAX_N; i++) { fac[i] = fac[i - 1] * i%mod; }for (int i = 0; i < MAX_N; i++) { inv[i] = POW(fac[i], mod - 2); } }
inline ll nCr(ll n, ll r) { return (fac[n] * inv[r] % mod)*inv[n - r] % mod; }
inline void PRI(ll n) { bool a[n + 1]; for (int i = 0; i < n + 1; i++) { a[i] = 1; }for (int i = 2; i < n + 1; i++) { if (a[i]) { prime.pb(i); ll b = i; while (b <= n) { a[b] = 0; b += i; } } } }

vector<vector<pair<int,int>>> Edge;
vector<int> node;

bool bellman_ford(int n,int s) {
	node = vector<int>(n,INF);
	node[s] = 0;
	REP (i,n) {
		REP (j,Edge.size()) {
			REP (k,Edge[j].size()) {
				int from = j,to = Edge[j][k].F;
				int cost = Edge[j][k].S;
				if (node[from] != INF && node[to] > node[from] + cost) {
					node[to] = node[from] + cost;
					if (i == n - 1 && to == n - 1) return true;
				}
			}
		}
	}
	return false;
}

signed main() {
	int n;
	cin >> n;
	int a[n];
	map<int,int> cnt;
	REP (i,n) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a,a+n);
	int MAX = a[n-2] + a[n-1];
	int p = 1;
	int beki = 0;
	while (p < MAX) {
		p *= 2;
		beki++;
	}
	int ans = 0;
	for (auto itr = cnt.begin();itr != cnt.end();itr++) {
		if (cnt[itr->first] <= 0) continue;
		int x = p;
		REP (i,beki) {
			x /= 2;
			if (itr->first == x / 2) {if (cnt[itr->first] >= 2) {ans += cnt[itr->first] / 2;cnt[itr->first] -= (cnt[itr->first]/2) * 2;break;}}
			if (itr->first < x / 2) {
				if (cnt.count(x - itr->first) == 1) {
					if (cnt[x-itr->first] <= 0) continue;
					int mi = min(cnt[itr->first],cnt[x-itr->first]);
					ans += mi;
					cnt[itr->first] -= mi;
					cnt[x-itr->first] -= mi;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}