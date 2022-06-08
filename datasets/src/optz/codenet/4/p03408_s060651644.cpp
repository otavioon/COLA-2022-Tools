#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<string> b, r;
    set<string> w;
    int n, m;
    cin >> n;
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        b.insert(s);
        w.insert(s);
    }
    cin >> m;
    for (int i=0; i<m; ++i) {
        string s; cin >> s;
        r.insert(s);
        w.insert(s);
    }
    int ans = 0;
    for (string s: w) {
        int cnt = 0;
        for (string t: b) {
            if (s == t) cnt++;
        }
        for (string t: r) {
            if (s == t) cnt--;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}