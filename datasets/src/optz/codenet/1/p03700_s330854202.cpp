#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define PAU system("pause")

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 28);
const double PI = acos(-1);

ll N, A, B;
vll H;
bool check(ll turn) {
	ll dis = A - B;
	ll cnt = 0;
	REP(i, N) {
		ll crt = H[i] - B * turn;
		if (crt > 0) {
			cnt += (crt + dis - 1) / dis;
		}
	}
	return cnt <= turn;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> A >> B;
	H = vll(N);
	REP(i, N)cin >> H[i];
	int ok = 10e9;
	int ng = 0;
	bool c = check(1);
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		if (check(mid))ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
	PAU;
	return 0;
}
