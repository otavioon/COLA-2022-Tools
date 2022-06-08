#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

vector<int> to[200005];
vector<int> ans;

void dfs(int v, int p=-1) {
    int d = ans[v];
    for (int u : to[v]) {
        if (u == p) continue;
        ans[u] += d;
        dfs(u,v);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ans.resize(n);
    rep(i,q) {
        int p, x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }
    dfs(0);
    rep(i,n) cout << ans[i] << endl;
    return 0;
}