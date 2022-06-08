#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int n;
int visited[100001];

void dfs(int x, int cnt) {
    visited[x] = cnt;
    for (int nx : adj[x]) {
        if (!visited[nx]) {
            dfs(nx, cnt + 1);
        }
    }
}

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u; cin >> u;
        adj[i].push_back(u);
    }

    dfs(1, 0);
    if (visited[2] == 0) {
        cout << "-1\n";
    } else {
        cout << visited[2] << '\n';
    }

    return 0;
}
