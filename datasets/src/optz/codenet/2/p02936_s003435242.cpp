#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int N, Q;
vector<vector<int>> E;
vector<int> ADD;
vector<int> RET;

void rec(int node, uint64_t add) {
    add += ADD[node];
    RET[node] += add;
    for(auto n: E[node]) {
        rec(n, add);
    }
}

int main() {
    cin >> N >> Q;
    E.resize(N);
    rep(i, N-1) {
        int a, b;
        cin >> a >> b;
        E[a-1].push_back(b - 1);
    }
    ADD.resize(N);
    rep(i, Q) {
        int p, x;
        cin >> p >> x;
        ADD[p-1] += x;
    }

    RET.resize(N);
    rec(0, 0);
    for(auto n: RET) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}

