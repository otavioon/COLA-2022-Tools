#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void rec(int parent, int self, int cntsum, vector<set<int>> &connect, vector<int> &cntarr, vector<int> &ans) {
    connect[self].erase(parent);
    for (auto itr = connect[self].begin(); itr != connect[self].end(); itr++) {
        int child  = *itr;
        int copycntsum = cntsum + cntarr[child];
        rec(self, child, copycntsum, connect, cntarr, ans);
    }
    ans[self] = cntsum;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<set<int>> connect(n);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b; a--, b--;
        connect[a].insert(b);
        connect[b].insert(a);
    }
    vector<int> cntarr(n);
    rep(i,q) {
        int p, x;
        cin >> p >> x; p--;
        cntarr[p] += x;
    }
    vector<int> ans(n);
    rec(-1, 0, cntarr[0], connect, cntarr, ans);
    rep(i,n) {
        cout << ans[i] << " ";
    }
    cout << endl;
}