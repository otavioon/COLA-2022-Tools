#include <bits/stdc++.h>
using namespace std;

struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) (1 + (int)((a) - 1)/(int)(b))
#define int long long

signed main() {
    int s[3] = {0,0,0};
    rep(i,3)rep(j,3){
        int t; cin >> t;
        s[i] += t;
    }
    bool ans = (s[0] % 3 == s[1] % 3) && (s[1] % 3 == s[2] % 3);
    cout << (ans ? "Yes" : "No") << endl;
}