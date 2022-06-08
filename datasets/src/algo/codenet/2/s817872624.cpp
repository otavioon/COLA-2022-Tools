#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    multiset<uint32_t> st;
    for (int _ = 0; _ < n; _++) {
        uint32_t x; cin >> x;
        st.insert(x);
    }
    int cnt = 0;
    while (st.size() > 2) {
        auto x = *st.rbegin();
        st.erase(--st.end());
        uint32_t pw = 1 << (32 - __builtin_clz(x));
        auto it = st.find(pw - x);
        if (it != st.end()) {
            cnt++;
            st.erase(it);
        }
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    cout << endl;
}
