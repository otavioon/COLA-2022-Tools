#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n, a, ans;
multiset < int > b;

signed main () { 
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        b.insert(a);
    }
    while (!b.empty()) {
        int x = *prev(b.end());
        b.erase(prev(b.end()));
        int to = (1 << (int(double(log(double(x))) / log(2.0)) + 1));
        auto it = b.find(to - x);
        if (it != b.end()) {
            b.erase(it);
            ++ans;
        }
    }
    printf("%d\n", ans);
}
