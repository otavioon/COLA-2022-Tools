#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()		// 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend()	// 降順ソート 例:sort(DESC(vec));
#define rep(i, n) for(int i = 0; i < n; i++)
#define Rep(i, n) for(int i = 1; i < n; i++)
#define In(vec) rep(i, n) cin>>vec[i];
#define ANS(s) cout << s << endl
#define inc(a, b) cin >> a >> b;

const int mod = 1000000007;
const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vii = vector<pair<int, int>>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
int round_int(int a, int b) { return (a + (b - 1)) / b; }


// 4,8方向に探索する際に用いる配列
int dx[4] = { 0,  0, 1, -1 };
int dy[4] = { 1, -1, 0,  0 };
//int dx[8] = { 1, 0, -1,  0, 1, -1, -1,  1 };
//int dy[8] = { 0, 1,  0, -1, 1,  1, -1, -1 };

constexpr auto MAX = 100010;

// ────────────────────────────────────────────────────

bool check[MAX] = { false };
vi a;
int cnt = 1;
int search(int val) {
	cnt++;

	if (check[a[val]]) return 0;
	if (a[val] == 2) return cnt;

	check[a[val]] = true;
	search(a[val]);
}

int main() {
	int n; cin >> n;
	a.resize(n + 1); Rep(i, n + 1) cin >> a[i];

	if (search(a[1])) {
		cout << cnt << endl;
	}
	else cout << -1 << endl;
}