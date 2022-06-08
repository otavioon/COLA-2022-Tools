#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define x() real()
#define y() imag()

typedef complex<double> point; // 2D point only
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldob;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef pair<ii, ll> ii_i;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;

// OST
template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// from: https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

const int INF = ~(1<<31);
const ll LINF = (1LL << 60);
const long double EPS = 1e-9;
const long double PI = acos(-1);

const int N = 41;
const int NN = 1001;
const int MOD = 1e9+7;
const int IMAX = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

ll n, Ma, Mb, ai[N], bi[N], ci[N], dp[N][N*21][N*21];

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// cout.precision(3); cout << fixed;
	// memset(dp, -1, sizeof dp);
	cin >> n >> Ma >> Mb;
	for (int i = 1; i <= n; ++i)
		cin >> ai[i] >> bi[i] >> ci[i];

	for (int i = 0; i <= n; ++i)
		for (int a = 0; a < N*11; ++a)
			for (int b = 0; b < N*11; ++b)
				dp[i][a][b] = IMAX;
	dp[0][0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int a = 0; a < N*21; ++a) {
			for (int b = 0; b < N*21; ++b) {
				if (dp[i][a][b] == IMAX)
					continue;
				dp[i+1][a][b] = min(dp[i+1][a][b], dp[i][a][b]);
				dp[i+1][a+ai[i]][b+bi[i]] = min(dp[i+1][a+ai[i]][b+bi[i]], dp[i][a][b]+ci[i]);
			}
		}
	}

	ll ans = IMAX;
	for (int a = 1; a < N*21; ++a) {
		for (int b = 1; b < N*21; ++b) {
			int g = __gcd(a,b);
			if (a/g == Ma and b/g == Mb)
				ans = min(ans, dp[n][a][b]);
		}
	}
	cout << (ans == IMAX ? -1 : ans) << endl;

	return 0;
}