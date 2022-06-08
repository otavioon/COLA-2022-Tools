#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P std::pair<int,int>
#define PiP std::pair<int,std::pair<int,int>>
#define all(v) v.begin(),v.end()
#define mkp std::make_pair
#define prique(T) std::priority_queue<T,vector<T>,greater<T>>
using namespace std;
template<class T> inline void chmax(T &a, T b) {
	a = std::max(a, b);
}
template<class T> inline void chmin(T &a, T b) {
	a = std::min(a, b);
}

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return x != 1;
}
int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i;
		res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m = mod) {
	int res = 1;
	x %= m;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)
		return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod ;
}
int get_rand(int MIN, int MAX) {
	std::random_device rnd;
	std::mt19937 mt32(rnd());
	std::uniform_int_distribution<int> engine(MIN, MAX);
	return engine(mt32);
}
struct BIT {
	vector<int> bit;
	int n;
	BIT(int x) {
		bit.resize(x + 1, 0);
		n = x;
	}
	void add(int x, int y) {
		while (x <= n) {
			bit[x] += y;
			x += x & -x;
		}
	}
	int sum(int x) {
		int res = 0;
		while (x > 0) {
			res += bit[x];
			x -= x & -x;
		}
		return res;
	}
};

struct UnionFind {
	vector<int> par, size;
	UnionFind(int x) {
		par.resize(x);
		size.resize(x, 1);
		rep(i,x)
			par[i] = i;
	}
	int find(int x) {
		if (par[x] == x)
			return x;
		return par[x] = find(par[x]);
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	int consize(int x) {
		return size[find(x)];
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)
			return;
		if (size[x] < size[y]) {
			par[x] = y;
			size[y] += size[x];
		} else {
			par[y] = x;
			size[x] += size[y];
		}
	}
};

struct Tree {
	int size;
	vector<int> par, depth;
	vector<int> doubling[30];
	vector<vector<int>> G;
	int root = 0;
	Tree(int x) {
		par.resize(x);
		depth.resize(x);
		rep(i,30)
		{
			doubling[i].resize(x, -1);
		}
		G.resize(x);
		size = x;
	}
	void add_edge(int x, int y) {
		G[x].push_back(y);
		G[y].push_back(x);
	}
	void dfs(int x) {
		for (int i : G[x]) {
			if (depth[i] == -1) {
				depth[i] = depth[x] + 1;
				doubling[0][i] = x;
				dfs(i);
			}
		}
	}
	void init() {
		rep(i,size)
			depth[i] = -1;
		depth[root] = 0;
		dfs(root);
		rep(i,29)
		{
			rep(j,size)
			{
				if (doubling[i][j] == -1)
					doubling[i + 1][j] = -1;
				else
					doubling[i + 1][j] = doubling[i][doubling[i][j]];
			}
		}
	}
	int lca(int x, int y) {
		if (depth[x] > depth[y])
			swap(x, y);
		for (int i = 29; i >= 0; i--) {
			if ((depth[y] - depth[x]) >> i & 1) {
				y = doubling[i][y];
			}
		}
		if (x == y)
			return x;
		for (int i = 29; i >= 0; i--) {
			if (doubling[i][x] != doubling[i][y]) {
				x = doubling[i][x];
				y = doubling[i][y];
			}
		}
		return doubling[0][x];
	}
};

struct RollingHash {
	int Base = 283;
	const int MASK30 = (1ll << 30) - 1;
	const int MASK31 = (1ll << 31) - 1;
	const int MOD = (1ll << 61) - 1;
	vector<int> hash, power;
	int calcmod(int val) {
		val = (val & MOD) + (val >> 61);
		if (val > MOD)
			val -= MOD;
		return val;
	}
	int mul(int x, int y) {
		int xu = x >> 31;
		int xd = x & MASK31;
		int yu = y >> 31;
		int yd = y & MASK31;
		int mid = xd * yu + xu * yd;
		int midu = mid >> 30;
		int midd = mid & MASK30;
		return calcmod(xu * yu * 2 + midu + (midd << 31) + xd * yd);
	}
	RollingHash(string s) {
		//Base=get_rand(1<<7,1<<8);
		int sz = s.size();
		hash.resize(sz + 1, 0);
		power.resize(sz + 1, 1);
		rep(i,sz)
		{
			hash[i + 1] = (mul(hash[i], Base) + s[i]) % MOD;
			power[i + 1] = mul(power[i], Base) % MOD;
		}
	}
	int get(int l, int r) {
		int res = (hash[r] - mul(hash[l], power[r - l]) + MOD) % MOD;
		return res;
	}
	int lcp(int x, int y) {
		int len = min(hash.size() - y, hash.size() - x);
		int ok = 0, ng = len + 1;
		while (ng - ok > 1) {
			int mid = (ok + ng) / 2;
			if (get(x, x + mid) == get(y, y + mid))
				ok = mid;
			else
				ng = mid;
		}
		return ok;
	}
};
struct Segtree {
	int size = 1;
	vector<int>dat, lazy;
	Segtree(int x) {
		while (size < x)size *= 2;
		dat.resize(size * 2 - 1, inf);
		lazy.resize(size * 2 - 1, inf);
	}
	void eval(int k, int l, int r) {
		chmin(dat[k], lazy[k]);
		if (r - l > 1) {
			chmin(lazy[k * 2 + 1], lazy[k]);
			chmin(lazy[k * 2 + 2], lazy[k]);
		}
		lazy[k] = inf;
	}
	void update(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
		if (r == -1)r = size;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			chmin(lazy[k], x);
			eval(k, l, r); return;
		}
		update(a, b, x, k * 2 + 1, l, (l + r) / 2);
		update(a, b, x, k * 2 + 2, (l + r) / 2, r);
		dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
	}
	int query(int a, int k = 0, int l = 0, int r = -1) {
		if (r == -1)r = size;
		eval(k, l, r);
		if (r - l == 1) {
			return dat[k];
		}
		if (a < (l + r) / 2) {
			return query(a, k * 2 + 1, l, (l + r) / 2);
		}
		return query(a, k * 2 + 2, (l + r) / 2, r);
	}
};
/*--------Library Zone!--------*/


signed main() {
	int k,x;cin>>k>>x;
	if(k*500>=x)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
