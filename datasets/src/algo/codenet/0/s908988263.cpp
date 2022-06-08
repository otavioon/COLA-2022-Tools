#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

typedef long long ll;

const int Inf = 1e9;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int bitCount(long bits) {
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    ll k;
    cin >> s >> k;
    int len = s.size();
    int cnt = 0;
    rep (i, len) {
        int j = i;
        while (s[j] == s[j + 1]) j++;
        if (j > i) cnt += (j - i + 1) / 2;
        i = j;
    }
    ll ans;
    ans = k * cnt;

    if (s[0] != s[len - 1]) {
        cout << ans << endl;
        return 0;
    }

    bool all = true;
    rep (i, s.size()) {
        if (s[0] != s[i]) all = false;
    }

    int start, end;
    int j = 0;
    while (s[0] == s[j]) j++;
    start = j;
    j = len - 1;
    while (s[len - 1] == s[j]) j--;
    end = len - 1 - j;
    if (all) {
        ans = 0;
        if (len % 2) {
            ll x = len * k;
            ans = x / 2;
        } else {
            ans = k * cnt;
        }        
        cout << ans << endl;
        return 0; 
    } else {
        if ((start + end) % 2) {
            cout << ans << endl;
            return 0;
        }
        if (start % 2 == 0) {
            cout << ans << endl;
            return 0;
        }
        ans += k - 1;
        cout << ans << endl;
        return 0;
    }

    return 0;
}

