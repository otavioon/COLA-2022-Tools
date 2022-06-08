#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cctype>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cstdlib>
#include <iomanip>
#include <list>
#include <regex>
using namespace std;
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define all(obj) (obj).begin(), (obj).end()
#define m_p make_pair
#define rond(a, b) ((a) + (b) - 1) / (b)
using lli = long long;
using vect = vector<lli>;
using vecvec = vector<vect>;
using ipair = pair<lli, lli>;
using p_q = priority_queue<lli>;
constexpr lli inf = 1e15;
constexpr lli mod = 1e9 + 7;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

class unionfind
{
public:
	int size;

	unionfind(int n) {
		size = n;
		for (int i = 0; i < n; i++) {
			par.push_back(i);
			rank.push_back(0);
			len.push_back(1);
		}
	};
	int find(int n) {
		if (par[n] == n)
			return n;
		else
			return par[n] = find(par[n]);
	};
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m) return;
		size--;
		if (rank[n] < rank[m]) {
			par[n] = m;
			len[m] += len[n];
		}
		else {
			par[m] = n;
			len[n] += len[m];
		}
		if (rank[n] == rank[m])
			rank[n]++;
	};
	bool same(int n, int m) {
		return find(n) == find(m);
	};
	int length(int n) {
		return len[find(n)];
	}
private:
	vect par;
	vect rank;
	vect len;
};

class seg_tree
{
public:
	seg_tree(vect v) {
		n = 1;
		while (n < v.size()) n *= 2;
		node.resize(n * 2 - 1);
		rep(i, v.size()) node[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--) node[i] = node[2 * i + 1] + node[2 * i + 2];
	};
	void update(int x, lli val) {
		x += n - 1;
		node[x] = val;
		while (x > 0) {
			x = (x - 1) / 2;
			node[x] = node[2 * x + 1] + node[2 * x + 2];
		}
	};
	lli getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return node[k];
		return getsum(a, b, 2 * k + 1, l, (l + r) / 2) + getsum(a, b, 2 * k + 2, (l + r) / 2, r);
	};
private:
	int n;
	vect node;
};

class lazy_seg_tree
{
public:
	lazy_seg_tree(vect v) {
		n = 1;
		while (n < v.size()) n *= 2;
		node.resize(n * 2 - 1, inf);
		lazy.resize(n * 2 - 1, inf);
		rep(i, v.size()) node[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
	};
	void eval(int k, int l, int r) {
		if (lazy[k] != inf) {
			node[k] = min(node[k], lazy[k]);
			if (r - l > 1) {
				lazy[2 * k + 1] = min(lazy[2 * k + 1], lazy[k]);
				lazy[2 * k + 2] = min(lazy[2 * k + 1], lazy[k]);
			}
			lazy[k] = inf;
		}
	};
	void update(int a, int b, lli x, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		eval(k, l, r);
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) {
			lazy[k] = min(lazy[k], x);
			eval(k, l, r);
		}
		else {
			update(a, b, x, 2 * k + 1, l, (l + r) / 2);
			update(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = min(node[2 * k + 1], node[2 * k + 2]);
		}
	};
	lli getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		if (r <= a || b <= l) return inf;
		eval(k, l, r);
		if (a <= l && r <= b) return node[k];
		return min(getmin(a, b, 2 * k + 1, l, (l + r) / 2), getmin(a, b, 2 * k + 2, (l + r) / 2, r));
	};
private:
	int n;
	vect node, lazy;
};

template<class T>
vector<pair<T, int>> rle(vector<T> vec) {
	vector<pair<T, int>> ans;
	ans.emplace_back(vec.front(), 1);
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] == ans.back().first)
			ans.back().second++;
		else
			ans.emplace_back(vec[i], 1);
	}
	return ans;
}

vect cum_sum(vect v) {
	vect ans(v.size() + 1);
	rep(i, v.size())
		ans[i + 1] = ans[i] + v[i];
	return ans;
}

vecvec cum_sum_2d(vecvec v) {
	vecvec ans(v.size() + 1, vect(v[0].size() + 1));
	rep(i, v.size())
		rep(j, v[0].size())
		ans[i + 1][j + 1] = ans[i + 1][j] + ans[i][j + 1] - ans[i][j] + v[i][j];
	return ans;
}

vector<bool> eratosthenes(int n) {
	vector<bool> ans(n + 1, 1);
	ans[1] = 0;
	for (int i = 2; i * i <= n; i++) {
		if (ans[i] == 0) continue;
		for (int j = i; i * j <= n; j++)
			ans[i * j] = 0;
	}
	return ans;
}

bool prime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

vector<ipair> fact(int n) {
	vector<ipair> ans;
	auto era = eratosthenes(floor(sqrt(n)));
	for (int i = 2; i * i <= n; i++) {
		if (era[i] == 0) continue;
		if (n % i == 0) {
			ans.emplace_back(i, 1);
			n /= i;
		}
		while (n % i == 0) {
			ans.back().second++;
			n /= i;
		}
	}
	if (n != 1)
		ans.emplace_back(n, 1);
	return ans;
}

lli gcd(lli a, lli b) {
	if (a < b)
		swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

#define lcm(a, b) (a) / gcd((a), (b)) * (b)

lli s[100000], t[100000];

int main() {
	int a, b;
	cin >> a >> b;
	cout << (a - 1) * (b - 1) << endl;
}