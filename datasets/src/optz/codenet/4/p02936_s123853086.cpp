#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(int argc, char **argv)
{
    int N, Q;
    cin >> N >> Q;
    int a[N - 1], b[N -1 ];
    int p[Q], x[Q];
    REP(i, N - 1) cin >> a[i] >> b[i];
    REP(i, Q) cin >> p[i] >> x[i];

    REP(i, N - 1) {
        a[i]--;
        b[i]--;
    }
    REP(i, Q) {
        p[i]--;
    }

    set<int> s[N];
    REP(i, N - 1) {
        s[a[i]].insert(b[i]);
        s[b[i]].insert(a[i]);
    }

    ll score[N];
    REP(i, N) score[i] = 0;
    REP(i, Q) {
        score[p[i]] += x[i];
    }
    bool visited[N];
    REP(i, N) visited[i] = false;
    deque<int> dq;
    dq.push_back(0);
    visited[0] = true;
    while(dq.size() != 0) {
        int parent = dq.front();
        dq.pop_front();
        for (auto itr = s[parent].begin(); itr != s[parent].end(); ++itr) {
            int child = (*itr);
            if (!visited[child]) {
                score[child] += score[parent];
                visited[child] = true;
                dq.push_back(child);
            }
        }
    }

    cout << score[0];
    FOR(i, 1, N) cout << " " << score[i];
    cout << endl;
    return 0;
}
