#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    set<char> st;
    while (k--) {
        char a;
        cin >> a;
        st.insert(a);
    }

    while (true) {
        string ans = to_string(n);
        bool flag = true;
        for (char an : ans) {
            if (st.find(an) != st.end()) {
                flag = false;
                n++;
                break;
            }
        }
        if (flag) {
            cout << ans << endl;
            return 0;
        }
    }
}
