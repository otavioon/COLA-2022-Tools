#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
 
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const ll INF = 1023456789;
 
#define REP(i,n)	for(int i=0;i<n;++i)
#define REPR(i,n)	for(int i=n-1;i>=0;--i)
#define FOR(i,s,n)	for(int i=s;i<n;++i)
#define FORR(i,s,n)	for(int i=n-1;i>=s;--i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define F			first
#define S			second

int n;
int a[100001], b[100001], c[100000];
int cb[100001], sb[100001];
 
int main(int argc, char **argv) {
	cin >> n;
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i];
	REP(i, n) cin >> c[i];
	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);
	a[n] = b[n] = 1000000001;

	int ai = 0;
	cb[0] = sb[0] = 0;
	REP(i, n) {
		for (; a[ai] < b[i]; ++ai) ++cb[i];
		cb[i + 1] = cb[i];
		sb[i + 1] = sb[i] + cb[i];
	}

	int bi = 0, res = 0;
	REP(i, n) {
		for (; b[bi] < c[i]; ++bi);
		res += sb[bi];
	}

	cout << res << endl;
	return 0;
}
 