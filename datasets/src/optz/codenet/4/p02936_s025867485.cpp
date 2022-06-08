#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

vector<int> par(200010);
vector<set<int>> st(200010);
vector<ll> c(200010), ans(200010);
void dfs(int i) {
    set<int> t = st[i];
    for (auto s : t) {
        if (par[s] != 0)
            continue;
        par[s] = i;
        dfs(s);
    }
}

ll f(int i) {
    if (ans[i] != 0)
        return ans[i];
    return ans[i] = f(par[i]) + c[i];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << fixed << setprecision(10);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);

    par[1] = 1;
    rep(i, 0, n - 1) {
        cin >> a[i] >> b[i];
        st[a[i]].insert(b[i]);
        st[b[i]].insert(a[i]);
    }
    dfs(1);
    rep(i, 0, q) {
        int p;
        ll x;
        cin >> p >> x;
        c[p] += x;
    }
    ans[1] = c[1];
    rep(i, 1, n + 1) {
        cout << f(i) << endl;
    }

    return 0;
}
