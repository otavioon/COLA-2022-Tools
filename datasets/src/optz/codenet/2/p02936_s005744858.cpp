#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

vector<vector<int>> to;
vector<int> ans;

void dfs(int v, int p) {
    for (int u : to[v]) {
        if (u == p)
            continue;

        ans[u] += ans[v];
        dfs(u, v);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    to.resize(n);
    ans.assign(n, 0);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    rep(i, q) {
        int p, x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }

    dfs(0, -1);

    rep(i, n) {
        if (i != 0)
            cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}