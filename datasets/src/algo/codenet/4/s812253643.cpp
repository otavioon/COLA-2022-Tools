#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <functional>
#include <algorithm>
#include <stack>
#include <list>
#include <queue>
#include <bitset>
#include <iostream>
#include <sstream>
using namespace std;
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define pf printf
#define sf scanf
#define deb(x) cerr << ">>>>>>>>>>>>>>>>>>>> "#x" = " << x << " <<<<<<<<<<<<<<<<<<<<\n"
#define debd(x) fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> %s = %d <<<<<<<<<<<<<<<<<<<<\n", #x, x)
#define debs(x) fprintf(stderr, ">>>>>>>>>>>>>>>>>>>> %s = %s <<<<<<<<<<<<<<<<<<<<\n", #x, x)
#define debll(x) fprint(stderr, ">>>>>>>>>>>>>>>>>>>> %s = %lld <<<<<<<<<<<<<<<<<<<<\n", #x, x)
#define fr(i, a, b) for(int i = a ; i < b ; i++)
#define frr(i, a, b) for(int i = a ; i >= b ; i--)
#define tr(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define trr(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define its(x) static_cast< ostringstream & >( ( ostringstream() << dec << x ) ).str()
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mems(a) memset(a, 0, sizeof(a))
#define has(cont, x) ((cont).find((x)) != (cont).end())
#define sz(x) ((int)(x).size())
//typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
//bitmask
int onbit(int x, int pos) {x |= (1 << pos); return x;}
int offbit(int x, int pos) {x &= ~(1 << pos); return x;}
int test(int x, int pos) {return x & (1 << pos);}
int flip(int x, int pos) {x ^= (1 << pos); return x;}
int lsb(int x) {return x & (-x);}
int onbitall(int x, int pos) {x = (1 << pos)-1; return x;}
//constants
const double EPS = 1e-9;
const double PI = 2*acos(0.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
//moves
const int dx1[] = {0, 1, 0, -1};
const int dy1[] = {1, 0, -1, 0};
const int dx2[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy2[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int k;
char n[123456];
set<int> s;

bool cek(int x) {
	string str = its(x);
	fr(i, 0, str.length()) {
		if(has(s, str[i]-'0')) return false;
	}
	return true;
}

int main() {
//  freopen("input.in", "r", stdin);
	sf("%s %d", n, &k);
	fr(i, 0, k) {
		int qwe;
		sf("%d", &qwe);
		s.insert(qwe);
	}

    int nn = atoi(n);
	fr(i, nn, INT_MAX-1) {
//		deb(i);
		if(cek(i)) {
			pf("%d\n", i);
			return 0;
		}
	}

	return 0;
}
