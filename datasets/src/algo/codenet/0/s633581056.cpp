#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string s;

int main()
{
    register ll k;
    cin >> s >> k;
    register ll len = s.length();
    if (len == 1) {
        printf("%lld\n", k / 2);
        return 0;
    }
    register ll ls = 0, rs = len - 1;
    while (ls < len && s[ls] == s[rs]) ++ls;
    if (ls > 0) --ls;
    while (rs >= 0 && s[rs] == s[ls]) --rs;
    if (rs < len) ++rs;
    register ll num = 1, ans = 0;
    for (register int i = ls + 1; i <= rs; ++i) {
        if (s[i] == s[i - 1]) {
            ++num;
        } else {
            ans += (num / 2) * k;
            num = 1;
        }
    }
    ++ls, ++rs;
    if (s[0] == s[len - 1]) {
        num = len - rs + 1 + ls;
        ans += (num / 2) * (k - 1);
        if (ls < rs) {
            ans += ls / 2;
            ans += (len - rs + 1) / 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
