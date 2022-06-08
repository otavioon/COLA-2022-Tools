#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> B(N - 1);
    for (int& x : B) cin >> x;

    int ans = 0;
    for (auto it = B.begin(); it != B.end(); it++) {
        auto t = next(it, 1);
        if (t == B.end()) {
            t = it;
        }
        ans += min(*it, *t);
    }
    ans += B.front();
    cout << ans << endl;
}
