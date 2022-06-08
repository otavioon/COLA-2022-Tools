#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

const ll MAX_N = 1e2 + 2, inf = 1000000LL * 1000000LL;
string s;
ll k;
ll dp[MAX_N][2];

ll calc (string t) {
    for (int i = 0; i < MAX_N; i++)
        dp[i][0] = dp[i][1] = inf;

    dp[0][0] = 0, dp[0][1] = 1;
    for (int i = 1; i < t.size(); i++) {
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        dp[i][0] = (t[i] == t[i - 1]? dp[i - 1][1]: min(dp[i - 1][1], dp[i - 1][0]));
    }

    return min(dp[t.size() - 1][0], dp[t.size() - 1][1]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> s >> k;
    if (s.size() == 1) {
        cout << k - 1 << "\n";
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

    string g = s;
    g[0] = 'A';
    ll ans = (k - 1) * calc(g) + calc(s) + k - 1;

    g = s;
    g[s.size() - 1] = 'A';
    ans = min(ans, (k - 1) * calc(g) + calc(s) + k - 1);

    if (k % 2) {
        g = s;
        g[0] = 'A', g[s.size() - 1] = 'B';
        ans = min(ans, (k / 2) * calc(g) + (k - (k / 2)) * calc(s) + k - 1);

        string h = s, l = s;
        h[0] = 'A', l[s.size() - 1] = 'A';
        ans = min(ans, (k / 2) * calc(s) + (k - (k / 2) - 2) * calc(g) + calc(h) + calc(l) + k - 1);
    }
    else {
        g = s;
        g[0] = 'A', g[s.size() - 1] = 'B';
        string h = s, l = s;
        h[0] = 'A', l[s.size() - 1] = 'A';

        ans = min(ans, calc(h) + (k / 2) * calc(s) + (k / 2 - 1) * calc(g) + k - 1);
        ans = min(ans, calc(l) + (k / 2) * calc(s) + (k / 2 - 1) * calc(g) + k - 1);
    }
    cout << ans << "\n";
    return 0;
}
