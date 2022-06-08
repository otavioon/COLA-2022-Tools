#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    bool prev = true;
    int cnt = 0;
    ll ans = 0;
    rep(i, s.size() - 1) {
        if(i < s.size() - 1) {
            if(s[i] == s[i + 1] && prev) {
                prev = false;
                cnt++;
            }
            else {
                prev = true;
            }
        }
        else {
            if(s[i] == s[0] && prev) ans = (ll) k - (ll) 1;
        }
    }
    ans += (ll) cnt * k;
    cout << ans << endl;
    return 0;
}
