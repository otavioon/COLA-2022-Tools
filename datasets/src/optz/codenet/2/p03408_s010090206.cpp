#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, a, b) for(int i = a; i < b; i++)

int main(){
    int n, m;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    cin >> m;
    vector<string> t(m);
    rep(i, 0, m) cin >> t[i];

    map<string, int> cnt;
    rep(i, 0, n) cnt[s[i]] = 0;
    rep(i, 0, n) cnt[s[i]] ++;
    rep(i, 0, m) cnt[t[i]] --;
    int ans = -101010;
    rep(i, 0, n) ans = max(ans, cnt[s[i]]);

    if(ans <= 0) cout << 0 << endl;
    else cout << ans << endl;
}