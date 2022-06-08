#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int a[MAXN];

int getp(int n) {
    int ans = 1;
    while (ans <= n) {
        ans <<= 1;
    }   
    return ans;
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    multiset <int> ms;
    for (int i = 0; i < n; ++i) {
        ms.insert(a[i]);
    }   

    int ans = 0;
    while (ms.size()) {
        auto u = *ms.rbegin();
        ms.erase(ms.find(*ms.rbegin()));
        int w = getp(u) - u;
        if (ms.find(w) != ms.end()) {
            ms.erase(ms.find(w));
            ++ans;
        }   
    }   

    cout << ans << '\n';
    return 0;
}   