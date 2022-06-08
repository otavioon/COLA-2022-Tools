#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int n;
    std::cin >> n;
    std::multiset<i64, std::greater<>> s;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        s.insert(a);
    }

    int ret = 0;
    while (!s.empty()) {
        auto mm = *s.begin();
        s.erase(s.begin());
        for (i64 x = 1; x <= 2 * mm; x *= 2) {
            if (x <= mm) continue;
            auto it = s.find(x - mm);
            if (it == s.end()) continue;
            s.erase(it);
            ret++;
            break;
        }
    }

    std::cout << ret << std::endl;

    return 0;
}