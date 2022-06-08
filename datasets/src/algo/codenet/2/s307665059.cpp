#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n;
    multiset <int> s;
    for (int i = 1; i <= n; i++) {
        cin >> x; s.insert(x);
    }
    int res = 0;
    while (s.size() > 0) {
        auto it = --s.end();
        s.erase(it);
        int x = *it;
        int cur = 1;
        while (cur <= x) {
            cur *= 2;
        }
        if (s.count(cur - x) > 0) {
            s.erase(s.find(cur - x));
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
