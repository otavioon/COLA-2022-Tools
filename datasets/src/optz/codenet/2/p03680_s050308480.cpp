#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MAX = 1e5 + 5;
vector<int> G[MAX];
bool vis[MAX];
void dfs(int s, int cnt, int &mndis) {
    //cout << s << " " << cnt << endl;
    if (s == 1) {
        mndis = min(cnt, mndis);
    }
    vis[s] = 1;
    for (auto u : G[s]) {
        if (!vis[u]) dfs(u, cnt + 1, mndis);
    }
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    forn(i, n) {
        int v;
        cin >> v;
        v--;
        G[i].pb(v);
    }
    memset(vis, 0, sizeof vis);
    int dis = 1e9;
    dfs(0, 0, dis);
    if (dis != 1e9) {
        cout << dis << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}