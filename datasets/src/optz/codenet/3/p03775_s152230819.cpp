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
#include <random>


using namespace std;
#define ll long long
#define lp(i,n) for(ll i=0;i<n;i++)

#define modd 1000000007
#define INF 8223372036854775807ll


typedef pair<long long, long long> pl;
typedef pair<double, double> pd;
typedef pair<ll, string> pls;



typedef string::const_iterator State;
class ParseError {};






/*

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


};*/

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

/*
class SegmentTree {



private:

	ll cont_num = 2;
	ll initial_v;
	vector<ll> dat;


public:


	SegmentTree(){};


	void init(ll size, ll initial_value) {

		cont_num = 2;
		initial_v = initial_value;

		while (cont_num < size) {
			cont_num *= 2;
		}

		dat.resize(2 * cont_num);//サイズ設定

		for (int i = 0; i < 2 * cont_num ; i++)dat[i] = initial_value;//初期化



	}


	void Update(ll position, ll value) {

		ll k = cont_num  + position;

		dat[k] = value;

		while (k > 1){
			k /= 2;
			dat[k] = min(dat[k * 2], dat[k * 2 + 1]);
		}


	}


	ll query_proces(ll a, ll b, ll k, ll l,ll r) {

		if (r <= a || b <= l)return initial_v;

		if (a <= l && r <= b)return dat[k];
		else {
			ll vl = query_proces(a, b, k * 2 , l, (l + r) / 2);
			ll vr = query_proces(a, b, k * 2 + 1, (l+r)/2, r);
			return min(vl, vr);
		}

	}


	ll query(ll left, ll right) {
		return query_proces(left,right,1,0,cont_num);
	}


};

*/


class SegmentTree {



private:

	ll cont_num = 2;
	pd initial_v;
	vector<pd> dat;


public:


	SegmentTree() {};


	void init(ll size, double initial_value_first, double initial_value_second) {

		cont_num = 2;
		initial_v.first = initial_value_first;
		initial_v.second = initial_value_second;

		while (cont_num < size) {
			cont_num *= 2;
		}

		dat.resize(2 * cont_num);//サイズ設定

		for (int i = 0; i < 2 * cont_num; i++)dat[i] = initial_v;//初期化



	}


	void Update(ll position, double value_f, double value_s) {



		ll k = cont_num + position;

		dat[k].first = value_f;
		dat[k].second = value_s;

		while (k > 1) {
			k /= 2;
			dat[k].first = dat[k * 2 + 1].first * dat[k * 2].first;
			dat[k].second = dat[k * 2 + 1].first * dat[k * 2].second + dat[k * 2 + 1].second;


		}


	}

	/*
	ll query_proces(ll a, ll b, ll k, ll l, ll r) {

		if (r <= a || b <= l)return initial_v;

		if (a <= l && r <= b)return dat[k];
		else {
			ll vl = query_proces(a, b, k * 2, l, (l + r) / 2);
			ll vr = query_proces(a, b, k * 2 + 1, (l + r) / 2, r);
			return min(vl, vr);
		}

	}


	ll query(ll left, ll right) {
		return query_proces(left, right, 1, 0, cont_num);
	}
	*/

	double query() {
		return dat[1].first + dat[1].second;
	}

};


template <typename T>
class Zip {
	vector<T> d;
	bool flag;
	void init() {
		sort(d.begin(), d.end());
		d.erase(unique(d.begin(), d.end()), d.end());
		flag = false;
	}
public:
	Zip() {
		flag = false;
	}
	void add(T x) {
		d.push_back(x);
		flag = true;
	}
	ll getNum(T x) {
		if (flag) init();
		return lower_bound(d.begin(), d.end(), x) - d.begin();
	}
	ll size() {
		if (flag) init();
		return (ll)d.size();
	}
};


ll N, M, K, a, b, c, d, e, H, W, L, T;
ll x, y;
ll A[2000004] = {};
ll B[2000004] = {};
ll C[2000004] = {};
ll D[1000006] = {};
ll E[1000006] = {};
bool f;
string S[200000];
string SS;
set <long long>sll;
pl bufpl;
vector <long long>vl[30005];
vector <long long>llv[30005];
vector <long long>vll;
vector <long long>v;
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
	ll cost;

	bool operator<(const ST& another) const
	{
		return first < another.first;//比較
	};

	bool operator>(const ST& another) const
	{
		return first > another.first;//比較
	};

};
//queue<ST> qst;
priority_queue<ST, vector<ST>, greater<ST> > qst;
multiset<ST> stmset;
ST bufst;
ST stt[100000];


/*vector <ST> vst;
ST st[200005];
ST bufst;
bitset<5000> bits;*/


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





ll zettai(ll aa) {

	if (aa < 0) {
		aa *= -1;
	}
	return aa;

}



class UnionFind
{

public:


	vector <ll>pairent;
	vector <ll>depth;
	vector <ll>size;


	UnionFind(ll Amount) : pairent(Amount, 1), depth(Amount, 1), size(Amount, 1) {

		for (ll i = 0; i < Amount; i++) {
			pairent[i] = i;
		}


	}


	ll FindPairent(ll x) {
		if (pairent[x] == x)return x;
		else return pairent[x] = FindPairent(pairent[x]);

	}


	ll Merge(ll x, ll y) {
		x = FindPairent(x);
		y = FindPairent(y);

		if (x != y) {
			if (depth[x] > depth[y]) {
				pairent[y] = pairent[x];
				return size[x] += size[y];
			}
			else {
				pairent[x] = pairent[y];
				if (depth[x] == depth[y]) {
					depth[y] ++;
				}

				return size[y] += size[x];
			}

		}
		else {
			return -1;
		}



	}



	bool IsSame(ll x, ll y) {
		if (FindPairent(x) == FindPairent(y))return true;
		else return false;
	}


	ll GetSize(ll x) {
		x = FindPairent(x);
		return size[x];
	}


};

class Nibutan {

public:
	ll hidari = 0;
	ll migi = 0;
	ll abc;
	vector<ll> contents;

	bool Jouken(int ser) {

		if (contents[ser] > abc) {
			return true;
		}
		else {
			return false;
		}

	}

	void Settings(int amount, ll terget) {
		migi = amount - 1;
		abc = terget;
	}


	ll tansaku() {

		hidari = -1;
		migi = contents.size();
		ll jud;

		while (hidari != migi - 1) {
			jud = hidari + migi;
			jud /= 2;
			if (Jouken(jud)) {
				migi = jud;
			}
			else {
				hidari = jud;
			}

		}

		return hidari;

	}


};



ll RepeatSquaring(ll N, ll P, ll M) {
	if (P == 0) return 1;
	if (P % 2 == 0) {
		ll t = RepeatSquaring(N, P / 2, M) % M;
		return t * t % M;
	}
	return N * RepeatSquaring(N, P - 1, M) % M;
}


SegmentTree seguki;

map<ll, ll> llmap;
map<char, ll> clmap;


int main() {

	cin >> N;

	a = N;
	b = 0;
	while (a > 0) {
		b++;
		a /= 10;
	}

	e = b;
	
	for (ll i = 2; i <= min(N,(ll)100001); i++) {
		if (N % i == 0) {
			a = N / i;
			b=0;
			c = 0;
			while (a > 0) {
				b++;
				a /= 10;
			}

			a = i;

			while (a > 0) {
				c++;
				a /= 10;
			}

			d = max(b, c);
			e = min(d, e);
		}
	}

	cout << e << endl;

	//cout << fixed << setprecision(10) << ansa << endl;
	return 0;




}
