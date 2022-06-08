#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n];
multiset<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        q.insert(a[i]);
    }
    int mx = 1 << 30;
    int ans = 0;
    while (mx > 1) {
        int cnt = 0;
        while (!q.empty()) {
            int x = *q.rbegin();
            if (x < mx / 2) {
                break;
            }
            q.erase(q.find(x));
            if (x == mx / 2) {
                ++cnt;
                continue;
            }
            auto it2 = q.find(mx - x);
            if (it2 != q.end()) {
                q.erase(it2);
                ++ans;
            }
        }
        mx /= 2;
        ans += cnt / 2;
    }
    printf("%d\n", ans);
    return 0;
}
