#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "trace.h"
#else
#define trace(args...)
#endif

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()

void solve(int test) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int lo = 1, hi = 1e9 + 8, mid;
    auto calc = [&](int x) {
        ll cur = 0;
        for (int& e : a) {
            cur += e / x;
            if (e % x == 0 && e >= x) cur--;
        }
        return (cur <= k);
    };
    while (lo < hi - 1) {
        mid = lo + (hi - lo) / 2;
        if (calc(mid))
            hi = mid;
        else
            lo = mid;
    }
    if (calc(lo)) hi = lo;
    cout << hi << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}
