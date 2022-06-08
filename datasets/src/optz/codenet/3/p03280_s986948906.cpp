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
#define modd 1000000007



typedef pair<long long, long long> pl;


typedef string::const_iterator State;
class ParseError {};




#define ll long long




class UnionFind {
public:
	vector <ll> par;
	vector <ll> siz;

	// Constructor
	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL){
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


class SegmentTree {
private:
	int n;
	vector <ll> node;

public:
	// 元の配列　v をセグメントツリーで表現する。
	SegmentTree(vector<ll> v) {
		//最下段のノード数は元配列のサイズ以上になる最小の2冪->これをnとおく。
		//セグ木全体で必要なノード数は2n-1個である。
		int sz = v.size();
		n = 1; 
		while (n < sz)n *= 2;

	}

};




long long N, M, K, a, b, c, d, e, H, W, L,T;
ll A[300005] = {};
ll B[300005] = {};
ll C[100][3005] = {};
bool f, ff;
string S,SS;
set <long long>sll;
pl bufpl;
vector <long long>vl[100005];
vector <long long>vll;
vector <pl>vpl;
vector <string> vs;
set<ll> llset[50];
multiset<ll> llmset;
queue<ll> ql;


struct ST
{
	ll first;
	ll second;
	ll kaisuu;
	

	bool operator<(const ST& another) const
	{
		return first < another.first;//比較
	};

};



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


ll minn, maxx;
double ansa;

ll zettai(ll aa) {

	if (aa < 0) {
		aa *= -1;
	}
	return aa;

}


bool itta[300000];

int main() {
	
	cin >> a>>b;

	a--;
	b--;

	cout << a*b << endl;

	//cout << fixed << setprecision(10) << ansa << endl;
	return 0;



}
