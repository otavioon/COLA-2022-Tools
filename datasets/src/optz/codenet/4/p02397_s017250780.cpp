#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<time.h>
#define int long long
#define double long double
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define ggr getchar();getchar();return 0;
#define prique priority_queue
constexpr auto mod = 1000000007;
#define inf 1e15
#define key 1e9
using namespace std;
typedef pair<int, int>P;
template<class T> inline void chmax(T& a, T b) {
	a = std::max(a, b);
}
template<class T> inline void chmin(T& a, T b) {
	a = std::min(a, b);
}
//combination(Nが小さい時はこれを使う
const int MAX = 330000;
int fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}

// 二項係数計算
long long COMB(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
bool prime(int n) {
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0)cnt++;
	}
	if (cnt != 1)return false;
	else return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}

//繰り返し二乗法（Nが大きい時の場合のcombination)
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= (i % mod); res %= mod;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}
//UnionFind
class UnionFind {
protected:
	int* par, * rank, * size;
public:
	UnionFind(unsigned int size) {
		par = new int[size];
		rank = new int[size];
		this->size = new int[size];
		rep(i, size) {
			par[i] = i;
			rank[i] = 0;
			this->size[i] = 1;
		}
	}
	int find(int n) {
		if (par[n] == n)return n;
		return par[n] = find(par[n]);
	}
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m)return;
		if (rank[n] < rank[m]) {
			par[n] = m;
			size[m] += size[n];
		}
		else {
			par[m] = n;
			size[n] += size[m];
			if (rank[n] == rank[m])rank[n]++;
		}
	}
	bool same(int n, int m) {
		return find(n) == find(m);
	}
	int getsize(int n) {
		return size[find(n)];
	}
};
int dight(int n) {
	int ans = 1;
	while (n >= 10) {
		n /= 10;
		ans++;
	}
	return ans;
}
int dight_sum(int n) {
	int sum = 0;
	rep(i, 20)sum += (n % (int)pow(10, i + 1)) / (pow(10, i));
	return sum;
}
int dight_min(int n) {
	int ans = 9;
	while (n >= 10) {
		ans = min(ans, n % 10);
		n /= 10;
	}
	ans = min(ans, n);
	return ans;
}
int dight_max(int n) {
	int ans = 0;
	while (n >= 10) {
		ans = max(ans, n % 10);
		n /= 10;
	}
	ans = max(ans, n);
	return ans;
}
signed main() {
	while (1) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0)break;
		cout << min(x, y) << " " << max(x, y) << endl;
	}
	ggr
}

