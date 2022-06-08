// 失敗するからこそ そこから立ち向かって行く強さがあってそんな強さが本当の強さだと私は思うから
// ぜったいあきらめない
#if defined(DAIJOBU)
#include "/home/ichigo/includes.hpp"
#include "/home/ichigo/debug.hpp"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#include <bits/stdc++.h>
#define deb(x...)
#endif
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long lint;
typedef vector<lint> vlint;
typedef vector<vlint> vvlint;
typedef pair<lint, lint> plint;
typedef double ld;

template<class T> bool chmin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool chmax(T &a, T b) { return a < b ? (a = b, true) : false; }



int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	if(n % 2)cout << 2 * n;
	else cout << n;
	return 0;
}

