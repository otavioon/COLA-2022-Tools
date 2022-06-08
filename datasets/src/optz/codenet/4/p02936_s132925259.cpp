#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define pll pair<ll, ll>
#pragma GCC optimize ("O3")
using namespace std;
vector <set <int>> tree (200001);
vector <int> add (200001, 0);
vector <bool> vis (200001, false);
void dfs (int ver) {
    vis[ver]=true;
    for (auto &i :  tree[ver]) {
        if (!vis[i]) {
            add[i]+=add[ver];
            dfs (i);
        }
    }
}
int main () {
    #ifdef LOCAL
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
        freopen ("error.txt", "w", stderr);
    #else
        ios::sync_with_stdio(false);
        cin.tie (NULL);
    #endif
    int n, q; cin>>n>>q;
    for (int i=1;i<n;++i) {
        int a, b; cin>>a>>b;
        tree[a].insert(b);
    }
    while (q--) {
        int p, x; cin>>p>>x;
        add[p]+=x;
    }
    dfs (1);
    for (int i=1;i<=n;++i) cout<<add[i]<<' ';
    return 0;
}
