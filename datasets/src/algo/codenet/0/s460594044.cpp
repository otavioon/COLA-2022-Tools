#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

typedef long long ll;

const ll MAX_N = 1e2 + 2, inf = 1000000LL * 1000000LL;
string s;
ll k;
ll dp[MAX_N][2];

ll calc (string t) {
    for (ll i = 0; i < MAX_N; i++)
        dp[i][0] = dp[i][1] = inf;

    dp[0][0] = 0, dp[0][1] = 1;
    for (ll i = 1; i < t.size(); i++) {
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        dp[i][0] = (t[i] == t[i - 1]? dp[i - 1][1]: min(dp[i - 1][1], dp[i - 1][0]));
    }

    return min(dp[t.size() - 1][0], dp[t.size() - 1][1]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> s >> k;
    if (s.size() == 1) {
        cout << (k / 2) << "\n";
        return 0;
    }

    if (k == 1) {
        cout << calc(s) << "\n";
        return 0; 
    }

    if (s[0] != s[s.size() - 1]) {
        cout << calc(s) * k << "\n";
        return 0;
    }
    assert(false);

    ll l = 1;
    for (ll i = 1; i < s.size(); i++)
        if (s[i] == s[0])
            l++;
        else
            break;

    if (l == s.size()) {
        cout << (1LL * s.size() * k) / 2 << "\n";
        return 0;
    }

    assert(false);
    ll r = 1;
    for (ll i = s.size() - 2; ~i; i--)
        if (s[i] == s[0])
            r++;
        else
            break;


    string g;
    for (ll i = l - 1; i + r - 1 < s.size(); i++)
        g += s[i];

    ll ans = (l / 2) + (r / 2) + ((l + r) / 2) * (k - 1) + calc(g) * k;
    cout << ans << "\n";
    return 0;
}
