#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream> 
#define _USE_MATH_DEFINES
#include <math.h>
#include <unordered_set>
#include<unordered_map>

using namespace std;


inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

template<class T> inline T sqr(T x) { return x*x; }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define VEC_2D(a,b) vector<vector<int> >(a, vector<int>(b, 0))
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define INF (1001000000)
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MOD 1000000007LL
#define MS(v,n) memset((v),(n),sizeof(v))

//input
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;

//output
#define P(p) cout<<(p)<<endl;
#define FSP(a) cout << fixed << setprecision(a)

template<typename T> T gcd(T x, T y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}

template<typename T> T lcm(T a, T b) {
	return a / gcd(a, b) * b;
}
template<typename T> bool is_prime(T n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return n != 1;
}
map<int, int> prime_factor(int n) {
	map<int, int> res;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}
int extgcd(int a, int b, int& x, int& y) {//
	int d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}



ll mod_pow(ll x, ll n, ll mod) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) res = res * x % mod;
	return res;
}
vector<string> split(const string &str, char delim) {
	vector<string> res;
	size_t current = 0, found;
	while ((found = str.find_first_of(delim, current)) != string::npos) {
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

bool is_kadomatsu(int a, int b, int c) {
	if (a == b || a == c || b == c)return false;
	if (a > b && c > b) return true;
	if (a < b && c < b)return true;
	return false;
}


struct UF {
	int n;
	vi d;
	UF() {}
	UF(int n) :n(n), d(n, -1) {}
	int root(int v) {
		if (d[v] < 0) return v;
		return d[v] = root(d[v]);
	}
	bool same(int a, int b) {
		return root(a) == root(b);
	}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (size(x) < size(y)) swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	int size(int v) { return -d[root(v)]; }
};



vector<int> divisor(int n) {
	if (n == 1) return{};
	vi res;
	for (int i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			res.emplace_back(i);
			if (i != 1 && i != n / i)res.emplace_back(n / i);
		}
	}
	return res;
}

struct Bellmanford {
	int n;
	struct edge {
		int from, to, cost;
	};
	vector<edge> E;
	vi d;
	Bellmanford(int n) :n(n), d(n) {
E.resize(n);
	}
	void add_edge(int x, int y, int cost) {
		edge e;
		e.from = x; e.to = y; e.cost = cost;
		E.push_back(e);
	}
	void shortest_path(int s) {
		rep(i, n)d[i] = INF;
		d[s] = 0;
		while (true) {
			bool update = false;
			for (auto e : E) {
				if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
					d[e.to] = d[e.from] + e.cost;
					update = true;
				}
			}
			if (!update) break;
		}
	}
};
struct Dijkstra {
	int n;
	struct edge {
		int to; ll cost;
	};
	vector<vector<edge>> G;
	vll d;
	Dijkstra(int n) :n(n), d(n) {
		G.resize(n);
	}
	void add_edge(int x, int y, ll cost) {
		edge e;
		e.to = y; e.cost = cost;
		G[x].push_back(e);
	}
	void shortest_path(int s) {
		rep(i, n)d[i] = 100000000000000000;
		d[s] = 0;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
		que.push(make_pair(0, s));

		while (!que.empty()) {
			pii p = que.top(); que.pop();
			int v = p.second;
			if (d[v] < p.first) continue;
			for (auto e : G[v]) {
				if (d[e.to] > d[v] + e.cost) {
					d[e.to] = d[v] + e.cost;
					que.push(make_pair(d[e.to], e.to));
				}
			}
		}
	}
};

struct Segmenttree {
	int n;
	vector<pair<ll, int>> dat;
	Segmenttree() {}
	void init(ll n_) {
		n = 1;
		while (n < n_) n *= 2;
		dat.resize(2 * n - 1);
		rep(i, 2 * n - 1)dat[i] = pair<ll, int>(-INF, -INF);
	}
	void update(int idx, ll val) {
		idx += n - 1;
		dat[idx] = make_pair(val, -(idx - n + 1));
		while (idx > 0) {
			idx = (idx - 1) / 2;
			dat[idx] = max(dat[idx * 2 + 1], dat[idx * 2 + 2]);
		}
	}
	pair<ll, int> query(int a, int b) {
		return query_seg(a, b, 0, 0, n);
	}
	pair<ll, int> query_seg(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return pair<ll, int>(-INF, -INF);
		if (a <= l && r <= b)return dat[k];
		else {
			return max(query_seg(a, b, k * 2 + 1, l, (l + r) / 2), query_seg(a, b, k * 2 + 2, (l + r) / 2, r));
		}
	}
};

struct Trie {
	Trie *next[26];

	Trie() {
		fill(next, next + 26, (Trie *)0);
	}

	void insert(char *s) {
		if (*s == '\0') return;
		if (this->next[*s - 'a'] == NULL) {
			this->next[*s - 'a'] = new Trie();
		}
		this->next[*s - 'a']->insert(s + 1);
	}

	bool find(char *s) {
		if (*s == '\0') return true;
		if (this->next[*s - 'a'] == NULL) {
			return false;
		}
		return this->next[*s - 'a']->find(s + 1);
	}
};

//------------------------------------


int main() {


	string a, b;
	cin >> a >> b;
	int n = a.length();
	rep(i, n) {
		if (a[i] != b[n - i - 1]) {
			P("NO");
			return 0;
		}
	}
	P("YES");
	return 0;
}



