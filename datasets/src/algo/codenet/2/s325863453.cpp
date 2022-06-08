#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);

int n, a, ans = -1, last;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (i > 1 && a < last) {
            ++ans;
        }
        last = a;
    }
    cout << (ans == -1 ? 1 : ans);
}
