#include <bits/stdc++.h>
using namespace std;

typedef vector<int> veci;
typedef pair<int, int> pii;
typedef vector<pii> vecii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vecl;
typedef vector<pll> vecll;
#define EPS (1e-9)
#define MOD (1e9 + 7)
#define fi first
#define se second
#define endl '\n'

void solve() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    ll cnt = 0;
    int n = s.size();

    bool same = true;
    char ch = s[0];
    for (auto c : s) {
        if (c!=ch) {
            same = false;
            break;
        }
    }

    if (n==1) {
        cout << k/2 << endl;
        return;
    }

    if (same) {
        cout << (ll(n)*k)/2 << endl;
        return;
    }

    int pre = n;
    if (s.back()==s.front()) {
        if (k>1) {
            pre = n-1;
            cnt += 1;
        }
    }

    int p = n-2;
    while (p>=0) {
        if (s[p]==s[p+1]) {
            if (pre!=p+1) {
                pre = p;
                cnt += 1;
            }
        }
        p -= 1;
    }

    cout << cnt*k << endl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL_TEST
    (void)argc;
    const string strpath = string(argv[0]) + string("-test.in");
    freopen(strpath.c_str(), "r", stdin);
    int tcs;
    cin >> tcs;
    while (tcs-- > 0)
#endif
        solve();
}
