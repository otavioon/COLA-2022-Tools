#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1]) {
            goto skip;
        }
    }
    cout << k * static_cast< long long >(s.size()) / 2 << endl;
    return 0;
skip:;
    if (s[0] == s[s.size() - 1]) {
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            if (i == 0) {
                while (j < s.size() - 1 && s[j] == s[j + 1]) {
                    j++;
                }
                cnt2 += j + 1;
            } else {
                while (j < s.size() - 1 && s[j] == s[j + 1]) {
                    j++;
                }
                if (j != s.size() - 1) {
                    cnt1 += (j - i + 1) / 2;
                    i = j;
                } else {
                    cnt3 += j - i + 1;
                    i = j;
                }
            }
        }
        cout << (cnt2 / 2 + cnt1 + cnt3 / 2) * k - (cnt2 / 2 + cnt3 / 2 - (cnt2 + cnt3) / 2) * (k - 1) << endl;
    } else {
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while (j < s.size() - 1 && s[j] == s[j + 1]) {
                j++;
            }
            cnt1 += (j - i + 1) / 2;
            i = j;
        }
        cout << cnt1 * k << endl;
    }
    return 0;
}