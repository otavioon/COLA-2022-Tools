// https://atcoder.jp/contests/agc039/tasks/agc039_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

int rcnt(string s) {
    int len = s.length();
    int cnt = 0;
    int ret = 0;
    REP(i, len - 1) {
        if (s[i] == s[i + 1]) {
            cnt++;
        } else {
            ret += (cnt + 1) / 2;
            cnt = 0;
        }
    }
    ret += (cnt + 1) / 2;
    return ret;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    int k;
    cin >> s >> k;
    int t1 = rcnt(s);
    int len = s.length();
    int t2 = 0;
    for (t2 = 1; t2 < len; t2++) {
        if (s[0] != s[t2]) {
            break;
        }
    }
    int t3 = 0;
    for (t3 = len - 1; t3 >= 0; t3--) {
        if (s[len - 1] != s[t3]) {
            break;
        }
    }
    int t4 = 0;
    if (s.front() == s.back() && t2 + t3 % 2 == 0) {
        t4 = 1;
    }
    cout << t1 * k + t4 * (k - 1) << endl;
    return 0;
}
