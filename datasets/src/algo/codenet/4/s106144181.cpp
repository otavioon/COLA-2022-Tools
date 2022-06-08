#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define FOR(i, a, n) for (int i = (a); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

int N, K;
set<int> st;

int dfs(int lev, int s) {
    if (s >= N) return s;
    int res = 1LL << 30;
    if (lev == 5) return res;
    for (int d : st) res = min(res, dfs(lev + 1, s * 10 + d));
    return res;
}

void _main() {
    cin >> N >> K;
    REP (i, 10) st.insert(i);
    REP (i, K) {
        int D;
        cin >> D;
        st.erase(D);
    }
    cout << dfs(0, 0) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    _main();
    return 0;
}