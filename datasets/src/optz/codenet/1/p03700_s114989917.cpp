#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <memory.h>



using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a,0,sizeof(a))
#define minus(a) memset(a,0xff,sizeof(a))
#define chmax(a,b) a=min((a),(b))
#define chmin(a,b) a=max((a),(b))


#define MOD 1000000007

typedef pair<int,int>P;
#define INF (1<<29)
 
struct edge { 
	int from, to; 
	edge (int from, int to){
		this->from=from; this->to=to;
	}
};
 
int V,E;
typedef vector<edge> edges;
vector<edges> G;

ll n, a, b;
ll h[100005];
ll work[100005];

bool check(ll m) {
	rep(i, n) {
		work[i] = h[i] - b*m;
	}
	ll cnt = 0;
	rep(i, n) {
		if (work[i] > 0) {
			cnt += (work[i] + (a - b - 1)) / (a - b);
		}

	}
	if (cnt > m)
		return false;
	else
		return true;
}

int main(){
	scanf("%lld %lld %lld ", &n, &a, &b);
	rep(i, n) {
		scanf("%lld ", &h[i]);
	}
	ll l = -1, r = 1000000005;
	ll mid;
	while (r - l > 1) {
		mid = (l + r) / 2;

		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
		
	}
	cout << r << endl;
	return 0;
}
