#include <bits/stdc++.h>
// statics
using namespace std;
using int64 = long long;
using PAIR = pair<int, int>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 77;
constexpr int MAX_M = 575;

// init/input
#define int int64
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...) type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T &t) {cin>>t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout <<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<"\n";
#define debug(x) cerr << #x << ":" << (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

int dp[MAX_N][MAX_M][MAX_M];

signed main() {
  INIT;
	VAR(int, n, ma, mb);
	vector< int > a(n), b(n), c(n);
	REP(i, n) {
		cin >> a[i] >> b[i] >> c[i];
	}
	REP(i, MAX_N) {
		REP(j, MAX_M) {
			REP(k, MAX_M) {
				dp[i][j][k] = INF;
				if (j == 0 && k == 0) dp[i][j][k] = 0;
			}
		}
	}

	REP(i, n) {
		REP(j, MAX_M) {
			REP(k, MAX_M) {
				dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]],
																						dp[i][j][k] + c[i]);
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
			}
		}
	}
	
	int ans = INF;
	FOR(i, 1, MAX_M) {
		if (max(ma * i, mb * i) >= MAX_M) break;
		ans = min(ans, dp[n][i * ma][i * mb]);
	}
	if (ans == INF) ans = -1;
	OUT(ans)BR;
  return 0;
}
