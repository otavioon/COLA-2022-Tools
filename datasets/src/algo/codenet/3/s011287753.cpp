#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define _abs(x)((x) < 0 ? (x) * -1 : (x))
#define _max(x, y)(max(0, max((x), (y))))
#define _min(x, y)(max(0, min((x), (y))))
template<typename T> inline bool __max__(T &x, const T &y) { return x < y ? x = y, 1 : 0; }
template<typename T> inline bool __min__(T &x, const T &y) { return x > y ? x = y, 1 : 0; }

#define pb push_back
#define mp make_pair

static const ll MOD = 1e9 + 7;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //freopen("debug.txt", "w", stderr);

    cin.tie(0);
    ios::sync_with_stdio(false);

    long n;

    cin >> n;

    ll a[n], b[n], c[n];
    ll ans = 0LL;

    long i, j, k;

    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) cin >> b[i];
    for (i = 0; i < n; i++) cin >> c[i];

    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);

    for (i = 0; i < n; i++) {
        if (b[n - 1] <= a[i]) break;

        for (j = 0; j < n; j++) {
            if (c[n - 1] <= b[j]) break;

            for (k = 0; k < n; k++) {
                if (a[i] < b[j] && b[j] < c[k]) ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
