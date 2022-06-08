#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();

    ll ans = 0;
    if (all_of(s.begin(), s.end(), [s](char x) { return x == s[0]; }))
        ans = n * k / 2;
    else {
        ll cnt = 0;
        rep(i, n - 1) {
            if (s[i] == s[i + 1] && s[i] == s[i + 2])
                cnt++, i += 1;
            else if (s[i] == s[i + 1])
                cnt++;
        }
        ans = cnt * k;
        if (s[0] == s[n - 1]) {
            int a = 0, b = 0;
            rep(i, n) {
                if (s[0] == s[i])
                    a++;
                else
                    break;
            }
            for (int i = n - 1; i >= 0; i--) {
                if (s[n - 1] == s[i])
                    b++;
                else
                    break;
            }
            ans -= (a / 2 + b / 2 - (a + b) / 2) * (k - 1);
        }
    }

    cout << ans << endl;
    return 0;
}
