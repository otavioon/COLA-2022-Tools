#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <stdio.h>
#include <queue>
#include <stack>
#include <deque>
#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <functional>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,a,n) for(int i = a; i < n; i++)
#define INF (1<<29)
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define fi first
#define se second 
#define pb push_back
#define PI 3.14159265358979323846
#define all(o) (o).begin(), (o).end()
#define rall(x) x.rbegin(),x.rend()


typedef double ld;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ld> vd;
typedef vector < vc > vvc;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long int ulli;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

const ld eps = 1e-10, pi = acos(-1.0);

#define MAX_N 100001

// combination

ll fact[MAX_N], factinv[MAX_N];
ll mod_pow(ll n, ll p, ll m) {
	ll a = n;
	ll x = 1;
	while (p) {
		if (p & 1) x = (x * a) % m;
		a = (a * a) % m;
		p >>= 1;
	}
	return x;
}
int extgcd(int a, int b, int& x, int&y) {
	int d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}
int mod_inverse(int a, int m) {
	int x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}
ll inv(ll n) {
	return mod_pow(n, MOD - 2, MOD);
}
void combInit() {
	fact[0] = 1;
	rrep(i, 1, MAX_N) fact[i] = fact[i - 1] * i % MOD;
	factinv[MAX_N - 1] = inv(fact[MAX_N - 1]);
	for (int i = MAX_N - 2; i >= 0; i--) factinv[i] = factinv[i + 1] * (i + 1) % MOD;
}

// ダイクストラ
/*
struct edge { int to, cost; };
vector < vector < edge > > G;
vi d;
void dijkstra(int s) {priority_queue<pii, vector< pii >, greater<pii> > que;d[s] = 0;que.push(pii(0, s));while (!que.empty()) {pii p = que.top(); que.pop();int v = p.second;if (d[v] < p.first) continue;rep(i, G[v].size()) {edge e = G[v][i];int cost = e.cost;if (d[v] + cost < d[e.to]) {d[e.to] = d[v] + e.cost;que.push(pii(d[e.to], e.to));}}}}
*/

// Union-Find木
int par[MAX_N], rnk[MAX_N], unionSize[MAX_N];
// はじめは全ての頂点が根
void UnionFindTreeInit(int n) {
	rep(i, n) {
		par[i] = i;
		rnk[i] = 0;
		unionSize[i] = 1;
	}
}
//木の根元を求める
int root(int x) {
	if (par[x] == x) return x; // 根を返す
	else return par[x] = root(par[x]);
}
// 連結成分の大きさを取得
int componentSize(int x) {
	return unionSize[root(x)];
}
// xとyが同じ集合に属するか否か
bool same(int x, int y) {
	return root(x) == root(y);
}
// xとyの属する集合を併合
void unite(int x, int y) {
	x = root(x);
	y = root(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) {
		par[x] = y;
		unionSize[y] += unionSize[x];
	}
	else {
		par[y] = x;
		if (rnk[x] == rnk[y]) rnk[x]++;
		unionSize[x] += unionSize[y];
	}
}


//-----------------------------------------------------------------

//int dx[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
//int dy[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };




struct edge { int to, cost; };
vector < vector < edge > > G;
vi d;
void dijkstra(int s) {
	priority_queue<pii, vector< pii >, greater<pii> > que;
	d[s] = 0;
	que.push(pii(0, s));

	while (!que.empty()) {
		pii p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;

		rep(i, G[v].size()) {
			edge e = G[v][i];
			int cost = e.cost;
			if (d[v] + cost < d[e.to]) {
				d[e.to] = d[v] + e.cost;
				que.push(pii(d[e.to], e.to));
			}
		}
	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	ll ans = 0;
	for (ll i = 1; i < sqrt(n); i++) {
		ll p = n / i;
		if ((n - (p * i)) == 0) {
			ans = p;
		}
	}
	cout << int(log10(ans)) + 1 << endl;

	return 0;
}




