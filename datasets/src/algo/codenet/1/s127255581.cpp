#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll c[3][3];
    ll sum = 0;
    rep(i, 3)
    {
        rep(j, 3)
        {
            cin >> c[i][j];
            sum += c[i][j];
        }
    }
    sum /= 3;
    if (sum - c[0][0] - c[1][1] == c[2][2] && sum - c[0][1] - c[1][2] == c[2][0] && sum - c[0][2] - c[1][0] == c[2][1]) {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}