#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;
    multiset<int> st;
    for (int _ = 0; _ < n; _++) {
        int x; cin >> x;
        st.insert(x);
    }
    int cnt = 0;
    while (st.size() > 2) {
        int x = *st.rbegin();
        st.erase(--st.end());
        int pw = 1 << (32 - __builtin_clz(x));
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
