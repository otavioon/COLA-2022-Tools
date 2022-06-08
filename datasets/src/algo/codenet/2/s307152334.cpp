// 
// 本番
//   2部マッチングやフローをしようとしたがLTE
// 本番後
//   LHiCの解答を理解 (https://beta.atcoder.jp/contests/agc029/submissions/3793091)
//   大きい数から順番に見ていく。大きい数とペアになれる数は常に一意。
//   例えばもっとも大きい数が 0b110101 とすると、これとペアになれるのは0b1010 + 1のみ。
//   数はmultisetで管理すると便利。ペアになったものから除去していく。

#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>


using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

int main(void)
{
	int N;
	cin >> N;
	multiset<ll> ms;
	REP(n, N) {
        ll a;
        cin >> a;
        ms.insert(a);
	}

    int ans = 0;
    while (!ms.empty()) {
        auto a = *ms.rbegin();
        ms.erase(ms.find(a));

        // ペアになる数は now - aで表せる
        ll now = 1;
        while(now <= a) now *= 2;
		auto it2 = ms.find(now - a);

		// ペアになる数が存在しない
		if (it2 == ms.end()) continue;

		// ペアになる数が存在する
		ms.erase(it2);
		++ans;
    }
	cout << ans << endl;
	return 0;
}
