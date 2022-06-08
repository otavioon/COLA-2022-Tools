#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/03/11  Problem: ABC 088 C / Link: http://abc088.contest.atcoder.jp/tasks/abc088_c  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 3;
	vector<vector<LL>> c(N, vector<LL>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> c[i][j];
		}
	}

	LL ans = 0LL;
	FOR(i, -200, 201) {
		FOR(j, -200, 201) {
			FOR(k, -200, 201) {
				VI a({ i,j,k });
				VI b(3);
				FOR(m, 0, 3) {
					b[m] = c[0][m] - a[0];
				}
				bool ok = 1;
				FOR(s, 0, N) {
					FOR(t, 0, N) {
						ok &= a[s] + b[t] == c[s][t];
					}
				}
				ans |= ok;
			}
		}
	}



	cout << (ans?"Yes":"No") << "\n";

	return 0;
}
