#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int bit_length(int x) {
    int len = 0;
    while ((1 << len) <= x) ++len;
    return len;
}

int main() {
    int n; cin >> n;
    multiset<int> se;
    while (n--) {
        int a; cin >> a; se.emplace(a);
    }
    int cnt = 0;
    while (!se.empty()) {
        int a = *se.rbegin();
        se.erase(--se.end());
        int b = (1 << bit_length(a)) - a;
        auto it = se.find(b);
        if (it == se.end()) continue;
        se.erase(it);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}