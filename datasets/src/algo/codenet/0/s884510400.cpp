//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int _i = 0; _i < (n); _i++) ni(a[_i])
#define nal(a, n) for (int _i = 0; _i < (n); _i++) nl(a[_i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pil pair<int, long long>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vil vector<pil>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 105;
const double eps = 1e-9;
char s[MAXN];
int dp[MAXN][2];

int main() {
	int n;
	scanf("%s", s);
	n = strlen(s);
	ll k; nl(k);
	int pre = 0, suf = n-1;
	for (; pre < n && s[0] == s[pre]; pre++);
	for (; suf >= 0 && s[n-1] == s[suf]; suf--);
	suf = n-suf-1;
	ll ans = pre / 2 + suf / 2;
	if (pre == n && suf == n)
		return !prl(((ll)n*k)/2);
	ll cnt = 0;
	for (int i = pre; i < n-suf; i++) {
		int j = i;
		for (; j < n && s[i] == s[j]; j++);
		cnt += (j-i) / 2;
		i = j-1;
	}
	if (s[0] != s[n-1]) {
		ans += cnt;
		prl(ans*k);
	} else {
		ans += k*cnt + (pre+suf)/2 * (k-1);
		prl(ans);
	}
	return 0;
}
