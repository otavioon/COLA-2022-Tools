#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
int N, Q;
vector<i64> X;
vector<set<int>> edge;

void recursive(int p, int before, i64 x) {
    if(before >= 0) edge[p].erase(before);
    X[p] += x;
    x = X[p];
    for(auto e : edge[p]) {
        recursive(e, p, x);
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    X = vector<i64>(N, 0);
    edge = vector<set<int>>(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].insert(b);
        edge[b].insert(a);
    }
    for(int q = 0; q < Q; q++) {
        int p, x;
        cin >> p >> x;
        p--;
        X[p] += x;
    }
    recursive(0, -1, 0);
    for(int i = 0; i < N; i++) {
        cout << (i ? " " : "") << X[i];
    }
    cout << endl;
    return 0;
}