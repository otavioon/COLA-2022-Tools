#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i, j, k) for(register int i = j; i <= k; ++i)
#define D(i, j, k) for(register int i = j; i >= k; --i)
#define random(x) (rand() % (x)) + 1
#define pb push_back
#define fi first
#define se second
#define pp pair<int, int>
#define mp make_pair
#define error(x) cerr << #x << "=" << x << endl
//***********var defination*********
const int maxn = 2e5+5;
int n, m, x, y, z;
int a[maxn], b[maxn], c[maxn];
int main() {
#ifdef orz
    freopen("input", "r", stdin);
#endif
    cin >> n;
    F(i, 1, n) cin >> a[i];
    F(i, 1, n) cin >> b[i];
    F(i, 1, n) cin >> c[i];
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    sort(c+1, c+1+n);
    int bb = n, cc = n;
    int tmp = 0, tmp2 = 0, ans = 0;
    D(aa, n, 1) {
	while(b[bb] > a[aa]) {
	    while(c[cc] > b[bb]) cc--, tmp++;
	    bb--;
	    tmp2 += tmp;
	}
	ans += tmp2;
    }
    cout << ans << endl;
    return 0;
}

