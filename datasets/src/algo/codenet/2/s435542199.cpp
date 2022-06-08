#include <bits/stdc++.h>

//#pragma GCC optimize("O3", "no-stack-protector")
//#pragma GCC target("sse4", "avx", "popcnt", "lzcnt", "sse3", "sse4.1", "sse4.2", "sse2", "tune=native")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0, a;
    multiset<int, greater<int>> kek;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        kek.insert(a);
    }
    while (!kek.empty()) {
        auto p = kek.begin();
        int v = *p;
        kek.erase(p);
        for (int i = 30; i >= 1; --i) {
            if (kek.count((1 << i) - v)) {
                ++ans;
                kek.erase(kek.find((1 << i) - v));
                break;
            }
        }
    }
    cout << ans;
    return 0;
}