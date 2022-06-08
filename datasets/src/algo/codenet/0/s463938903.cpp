#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) { return a * b * gcd(a, b); }

bool compareP(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int f, l = 0, c = 0;
    ll ans = 0;
    bool flag = true;
    while (c < s.size()) {
        int cnt = 1;
        char tmp = s[c];
        while (c < s.size() && s[c + 1] == tmp) {
            cnt++;
            c++;
        }
        if (flag) {
            f = cnt;
            flag = false;
        } else if (c == s.size() - 1)
            l = cnt;
        else
            ans += cnt / 2;
        c++;
    }
    ans *= k;
    if (f == s.size())
        ans += (f * k) / 2;
    else if(s[0] == s[c - 1])
        ans += ((f + l) / 2) * (k - 1) + (f / 2) + (l / 2);
    else
        ans += ((f / 2) + (l / 2)) * k;
    cout << ans << endl;
}