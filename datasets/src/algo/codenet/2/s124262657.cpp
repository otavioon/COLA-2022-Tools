#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    multiset <int> s;
    for (int i = 1; i <= n; i++) {
        cin >> x; s.insert(x);
    }
    int res = 0;
    while (s.size() > 0) {
        auto it = --s.end();
        int x = *it;
        int cur = 1;
        while (cur <= x) {
            cur *= 2;
        }
        if (s.count(cur - x) > (cur - x == x)) {
            s.erase(s.find(cur - x));
            res++;
        }
        s.erase(it);
    }
    cout << res << endl;
    return 0;
}
