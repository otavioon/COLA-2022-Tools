#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
        string a;
        cin >> a;
        ll k;
        cin >> k;
        int len = a.size();
        if (len == 1) {
                cout << k / 2 << endl;
        } else if (len == 2) {
                if (a[0] == a[1]) {
                        cout << k << endl;
                } else {
                        cout << 0 << endl;
                }
        } else {
                bool flg = 1;
                for (int i = 1; i < len; i++) {
                        if (a[i] != a[0]) {
                                flg = 0;
                                break;
                        }
                }
                if (flg) {
                        cout << 1LL * len * k / 2 << endl;
                        return 0;
                }
                ll ans = 0;
                char ch = '0';
                int now = 0;
                for (int i = 0; i <= len; i++) {
                        if (i == len || a[i] != ch) {
                                ans += now / 2;
                                ch = a[i];
                                now = 1;
                                continue;
                        }
                        now++;
                }
                int l = 0, r = 0;
                if (a[0] == a[len - 1]) {
                        for (l = 0; l < len; l++)
                                if (a[l] != a[0]) {
                                        l--;
                                        break;
                                }
                        for (r = len - 1; r >= 0; r--)
                                if (a[r] != a[0]) {
                                        r++;
                                        break;
                                }
                        r = len - r;
                        l++;
                        ans -= l / 2 + r / 2;
                }
                ans *= k;
                ans += 1LL * (l + r) / 2 * (k - 1);
                ans += l / 2 + r / 2;
                cout << ans << endl;
        }
}
