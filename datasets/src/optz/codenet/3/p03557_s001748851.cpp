#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <sstream>
#include <numeric>
// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>

///////////////////////////////////////////////////////////////
// namespace
///////////////////////////////////////////////////////////////
using namespace std;
// namespace mp = boost::multiprecision;

///////////////////////////////////////////////////////////////
// types
///////////////////////////////////////////////////////////////
using pii = pair<int, int>;
using ll = long long int;
using ld = long double;
// using mpi = mp::cpp_int;
// using mpf = mp::number<mp::cpp_dec_float<1024>>;

///////////////////////////////////////////////////////////////
// mod https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
///////////////////////////////////////////////////////////////
// ll MOD = 1000000007;
// ll mod(long long val) {
//     long long res = val % MOD;
//     if (res < 0) res += MOD;
//     return res;
// }
// ll modinv(ll a) {
//     ll b = MOD, u = 1, v = 0;
//     while (b) {
//         ll t = a / b;
//         a -= t * b; swap(a, b);
//         u -= t * v; swap(u, v);
//     }
//     u %= MOD;
//     if (u < 0) u += MOD;
//     return u;
// }

int n;
vector<int> a;
vector<int> b;
vector<int> c;

int main() {
    cin >> n;
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < n; ++i) {
        cin >> t;
        b.push_back(t);
    }
    for (int i = 0; i < n; ++i) {
        cin >> t;
        c.push_back(t);
    }

    vector<int> sums(n + 1, 0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    for (int i = 0; i < n; ++i) {
        int e = b[i];
        auto it = lower_bound(c.begin(), c.end(), e + 1);
        sums[i + 1] += distance(it, c.end());
        sums[i + 1] += sums[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int e = a[i];
        auto it = lower_bound(b.begin(), b.end(), e + 1);
        int ix = distance(b.begin(), it);
        ans += sums[n] - sums[ix];
    }

    cout << ans << endl;

    return 0;
}
