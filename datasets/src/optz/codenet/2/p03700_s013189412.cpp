#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>
#include <functional>

using namespace std;
#define ALL(x)              (x).begin(),(x).end()
#define REP(i, n)           for (int (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)       for (int (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF                 (int)2e9
#define MOD                 (1000 * 1000 * 1000 + 7)
#define Ceil(x, n)          (((((x))+((n)-1))/n))
#define CeilN(x, n)         (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)        ((x)-(x)%(n))
#define IsOdd(x)            (((x)&0x01UL) == 0x01UL)
#define IsEven(x)           (!IsOdd((x)))
#define M_PI                3.14159265358979323846
typedef long long           ll;
typedef pair<ll, ll>        P;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
ll N, A, B;
vector<ll> h;
bool compExec(ll cnt, vector<ll> h)
{
	REP(i, N) {
		h[i] -= B * cnt;
	}

	ll diff = A - B;
	ll nokoriCnt = 0;
	REP(i, N) {
		if (0 < h[i]) {
			nokoriCnt += Ceil(h[i], diff);
		} else {
			break;
		}
	}
	return nokoriCnt <= cnt;
}

int main()
{
	vector<ll> h;
	cin >> N >> A >> B;
	h.resize(N);
	REP(i, N) cin >> h[i];
	sort(h.rbegin(), h.rend());

	ll lb = 0;
	ll lu = (ll)1e14;
	ll mid = 0;
	while ((lb + 1) != lu) {
		mid = (lb + lu) / 2;
		if (!compExec(mid, h)) {
			lb = mid;
		} else {
			lu = mid;
		}
	}

	cout << lu << endl;
	return 0;
}
