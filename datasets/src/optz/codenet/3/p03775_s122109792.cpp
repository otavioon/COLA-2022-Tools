#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <string>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <tuple>
#include <numeric>
#include <functional>

using namespace std;

/*-------------------------------------------------------------------------------
　定義
 -------------------------------------------------------------------------------*/
#define ALL(a)					(a).begin(),(a).end()
#define REP(i, n)				for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n)			for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define INF						(1000 * 1000 * 1000 * 2)
#define MOD						(1000 * 1000 * 1000 + 7)
#define Ceil(x, n)				(((((x))+((n)-1))/n))		/* Nの倍数に切り上げ割り算 */
#define CeilN(x, n)				(((((x))+((n)-1))/n)*n)		/* Nの倍数に切り上げ */
#define FloorN(x, n)			((x)-(x)%(n))				/* Nの倍数に切り下げ */
#define IsOdd(x)				(((x)&0x01UL) == 0x01UL)			
#define IsEven(x)				(!IsOdd((x)))						
#define	BitSetV(Val,Bit)		((Val) |= (Bit))			
#define	BitTstV(Val,Bit)		((Val) & (Bit))				
#define M_PI					3.14159265358979323846
typedef long long				ll;
typedef pair<ll, ll>			P;

/*-----------------------------------------------------------------------------
　処理
 -------------------------------------------------------------------------------*/
/* 約数の列挙 */
vector<ll> divisorExec(ll n)
{
	vector<ll> res;
    for(ll i = 1; i <= sqrt(n); i++){
		if ((n % i) == 0) {
			res.push_back(i);
			if ((i * i) != n) {
				res.push_back(n / i);
			}
		}
	}
	sort(res.begin(), res.end());
	return res;
}

/* 桁数を返す */
ll find_digits(ll n)
{
	ll digit = 0;

	while(n) {
		n /= 10;
		digit++;
	}
	return digit;
}

// メイン
int main()
{
	ll N;
	cin >> N;
	vector<ll> yakusu = divisorExec(N);

	ll ans = INF;
	for(ll i = 0; i <  yakusu.size(); i++) {
		for (ll j = yakusu.size() - 1; 0 <= j; j--) {
			if (N == yakusu[i] * yakusu[j]) {
				ll digitOne1 = find_digits(yakusu[i]);
				ll digitOne2 = find_digits(yakusu[j]);
				ll ansOne = max(digitOne1, digitOne2);
				ans = min(ans, ansOne);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

