// https://atcoder.jp/contests/abc042/tasks/arc058_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    set<int> st;
    REP(i, N) st.insert(i);
    REP(i, K) {
        int t;
        cin >> t;
        st.erase(t);
    }
    string NS = to_string(N);
    REP(i, N * 10) {
        string NI = to_string(i);
        for (auto &x : NI) {
            if (st.count(x - '0') == 0) {
                break;
            }
            if (NS.length() <= NI.length() && NS <= NI) {
                cout << NI << endl;
                return 0;
            }
        }
    }

    return 0;
}
