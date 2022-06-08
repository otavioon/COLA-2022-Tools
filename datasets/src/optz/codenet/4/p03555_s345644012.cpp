//#pragma once
#include <stdio.h>
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
#include<bitset>

using namespace std;
#define modd 1000000007


typedef pair<long long, long long> pl;



#define ll long long




/*
class UnionFind {
public:
	vector <ll> par;
	vector <ll> siz;
	vector <ll> gr;

	// Constructor
	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) ,gr(sz_){
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


long long N, M, K, a, b, c, d, e, H, W, L;
long long A[200005] = {};
char B[500][500] = {};
long long C[205][205] = {};
long long D[200005] = {};
long long E[200005] = {};
bool f, ff;
string S[2];
set <long long>sll;
pl bufpl;
vector <long long>vl;
vector <pl>vpl;
vector <string> vs;
set<ll> llset;

/*struct ST
{
	long long Kati;
	int bangou;

	bool operator<(const ST& another) const
	{
		return Kati < another.Kati;//比較
	};

};



vector <ST> vst;
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


bool fs[2005][2005] = {};

int main() {


	cin >> B[0][0]>>B[0][1]>>B[0][2];
	cin >> B[1][0] >> B[1][1] >> B[1][2];
	
	

	if (B[0][0] == B[1][2] && B[0][1] == B[1][1] && B[0][2] == B[1][0]) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;

}
