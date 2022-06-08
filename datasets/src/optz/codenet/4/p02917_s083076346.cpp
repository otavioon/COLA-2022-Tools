//#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cctype>
#include <cstdlib>      // srand,rand


using namespace std;
#define ll long long

#define modd 1000000007
#define INF 1000000000000000000ll


typedef pair<long long, long long> pl;



typedef string::const_iterator State;
class ParseError {};








class UnionFind {
public:
	vector <ll> par;
	vector <ll> siz;

	// Constructor
	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
		for (ll i = 0; i < sz_; ++i) par[i] = i;
	}
	void init(ll sz_) {
		par.resize(sz_);
		siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
		for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}

	// Member Function
	// Find
	ll root(ll x) { // 根の検索
		while (par[x] != x) {
			x = par[x] = par[par[x]]; // x の親の親を x の親とする
		}
		return x;
	}

	// Union(Unite, Merge)
	bool merge(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;

		// merge technique（データ構造をマージするテク．小を大にくっつける）
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}



	bool issame(ll x, ll y) { // 連結判定
		return root(x) == root(y);
	}

	ll size(ll x) { // 素集合のサイズ
		return siz[root(x)];
	}


};

/*
struct SegmentTree {
private:
	ll n;
	vector<ll> node;

public:
	// 元配列 v をセグメント木で表現する
	SegmentTree(vector<ll> v) {
		// 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
		// セグメント木全体で必要なノード数は 2n-1 個である
		ll sz = v.size();
		n = 1; while (n < sz) n *= 2;
		node.resize(2 * n - 1, INF);

		// 最下段に値を入れたあとに、下の段から順番に値を入れる
		// 値を入れるには、自分の子の 2 値を参照すれば良い
		for (ll i = 0; i < sz; i++) node[i + n - 1] = v[i];
		for (ll i = n - 2; i >= 0; i--) node[i] = min(node[2 * i + 1], node[2 * i + 2]);
	}


	void update(ll x, ll val) {
		// 最下段のノードにアクセスする
		x += (n - 1);

		// 最下段のノードを更新したら、あとは親に上って更新していく
		node[x] = val;
		while (x > 0) {
			x = (x - 1) / 2;
			node[x] = min(node[2 * x + 1], node[2 * x + 2]);
		}
	}

};
*/


ll N, M, K, a, b, c, d, e, H, W, L, T;
ll x, y;
ll A[400005] = {};
ll B[400005] = {};
ll C[400005] = {};
ll D[400005] = {};
ll E[400005] = {};
bool f, ff;
string S[200000];
string SS;
set <long long>sll;
//pl bufpl;
vector <long long>vl[600005];
vector <long long>vll;
vector <pl>vpl;
vector <string> vs;
set<ll> llset;
multiset<ll> llmset;
queue<ll> ql;
multiset<pl> plmset;


struct ST
{
	ll first;
	ll second;
	ll kaisuu;


	/*bool operator<(const ST& another) const
	{
		return first < another.first;//比較
	};*/

};
queue<ST> qpl;
ST bufpl;


/*vector <ST> vst;
ST st[200005];
ST bufst;
bitset<5000> bits;*/

/*
long long modinv(long long aa, long long mm) {
	long long bb = mm, uu = 1, vv = 0;
	while (bb) {
		long long tt = aa / bb;
		aa -= tt * bb; swap(aa, bb);
		uu -= tt * vv; swap(uu, vv);
	}
	uu %= mm;
	if (uu < 0) uu += mm;
	return uu;
}


*/


ll zettai(ll aa) {

	if (aa < 0) {
		aa *= -1;
	}
	return aa;

}





/*
struct edge {
	ll from;
	ll to;
	ll cost;
};



ll V, E, d[300000];
edge es[300000];
bool fa[5000][5000];
bool ffa[5000];

bool has_negative_loop(ll s) {
	fill(d, d + V, 50000000000000000);
	d[s] = 0;
	for (ll i = 0; i <=2* V+1; i++) {
		for (ll j = 0; j < E; j++) {
			edge e = es[j];
			if (d[(int)e.to] > d[(int)e.from] + e.cost) {
				d[(int)e.to] = d[(int)e.from] + e.cost;
				if (i >= V+1 && fa[(int)e.to][V-1]==true &&fa[0][(int)e.from] == true) {
					return true;
				}
			}
		}
	}
	return false;
}
*/

/*struct cww { cww() { ios::sync_with_stdio(false); cin.tie(0); } }star;


bool is_prime[1000000 + 1];
vector<int> P;
void Eratosthenes(const int N)
{
	for (int i = 0; i <= N; i++)
	{
		is_prime[i] = true;//初期化
	}
	for (int i = 2; i <= N; i++)
	{
		if (is_prime[i])
		{
			for (int j = 2 * i; j <= N; j += i)
			{
				is_prime[j] = false;
			}
			P.emplace_back(i);
		}
	}
}*/

ll t;

ll RepeatSquaring(ll N, ll P, ll MO) {
	if (P == 0) return 1;
	if (P % 2 == 0) {
		ll t = RepeatSquaring(N, P / 2, MO);
		return t * t % MO;
	}
	return N * RepeatSquaring(N, P - 1, MO);
}

ll gyakugen(ll numb,ll MO) {
	return RepeatSquaring(numb, MO - 2, MO);
}

ll Com(ll NN, ll KK) {
	e = D[NN];
	e *= C[KK];
	e %= modd;
	e *= C[NN - KK];
	e %= modd;
	return e;

}

int main() {
	cin >> N;

	for (int i = 0; i < N-1; i++)cin >> A[i];

	a = A[0];
	a += A[N - 2];

	for (int i = 1; i < N - 1; i++)a += min(A[i - 1], A[i]);
	
	cout << a << endl;
	

	//cout << fixed << setprecision(10) << ansa << endl;
	return 0;



}
