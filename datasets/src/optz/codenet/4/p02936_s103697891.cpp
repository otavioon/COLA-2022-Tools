#include <bits/stdc++.h>
#define repp(i, l, r) for (long long i = (l); i < (r); i++)
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define per(i, n) for (long long i = (n); i >= 0; --i)
#define all(v) v.begin(), v.end()
const int INF = 1 << 30;
const long long LINF = 1LL << 60;
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

vector<vector<int>> graph;
vector<set<int>> part_tree;

int value = 0;

void dfs(int i,int root){
    for (auto next : graph[i]) dfs(next,root);
    part_tree[i].insert(root);
    return;
}

//ミョ(-ω- ?)
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    graph.resize(n);
    part_tree.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }
    vector<int> v(n);
    rep(i, q) {
        int r;
        cin >> r >> value;
        dfs(r-1,r-1);
        v[r-1] += value;
    }
    vector<int> res(n, 0);
    rep(i, n) {
        for (auto a : part_tree[i]) res[i] += v[a];
    }
    rep(i, n) cout << (i ? " " : "") << res[i];
    cout << "\n";
    return 0;
}