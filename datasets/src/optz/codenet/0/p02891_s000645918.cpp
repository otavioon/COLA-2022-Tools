#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    ll k;
    cin >> k;
    bool prev = true;
    ll cnt = 0;
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
            if(s[i] == s[0] && prev) ans = k - 1;
        }
    }
    ans += cnt * k;
    cout << ans << endl;
    return 0;
}
