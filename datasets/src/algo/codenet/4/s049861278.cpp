#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, k;
    cin >> n >> k;
    set < char > ban;
    for (int i = 0; i < k; ++i) {
        char d;
        cin >> d;
        ban.insert(d);
    }
    for (int i = n; i < 1000000; ++i) {
        string s = to_string(i);
        bool good = 1;
        for (auto d: s) {
            if (ban.find(d) != ban.end())
                good = 0;
        }
        if (good) {
            cout << s << '\n';
            break;
        }
    }
}
