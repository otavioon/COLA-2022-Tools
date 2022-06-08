#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 2e5 + 1;
const int inf = 1e9;
bool f[N];
void solve() {
    int i, j, k, n;
    string s;
    cin >> s >> k;
    int ansfirst = 0;
    for (i = 1; i < s.size(); ++i)
    if (s[i] == s[i - 1] && (i == 1 || !f[i - 1]))
        ++ansfirst, f[i] = 1;
    int ans = k * ansfirst;
    if (s[0] == s[s.size() - 1] && !f[s.size() - 1]) {
        for (i = 1; i < s.size(); ++i)
        if (s[i] == s[i - 1] && (i == 1 || !f[i - 1]))
            f[i] = 0;
        f[0] = 1;
        int anssecond = 1;
        for (i = 1; i < s.size(); ++i)
        if (s[i] == s[i - 1] && (!f[i - 1]))
            ++anssecond, f[i] = 1;
        if (f[s.size() - 1])
            ans += (k / 2) *(anssecond - ansfirst);
        else
            ans += (k - 1) * (anssecond - ansfirst);
    }
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
}
