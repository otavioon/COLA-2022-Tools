#ifdef DEBUG

#else

#    pragma GCC optimize("O3,no-stack-protector")
#    pragma GCC optimize("unroll-loops")

#    if __cplusplus < 201703L
#        pragma GCC target("avx")
#    else
#        pragma GCC target("avx2")
#    endif

#endif

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;
typedef long double Ld;

using namespace std;
using Graph = vector<vector<Int>>;

const Ld pi = M_PI;
const Int MOD = 1000000007;
const Int INF = 1LL << 61;

Int Floor(Int a, Int b) {
    return (a - (a % b)) / b;
}

Int Ceil(Int a, Int b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return Floor(a, b) + 1;
    }
}

vector<Int> divisor(Int n) {
    vector<Int> ret;
    for (Int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

Int digits(Int n) {
    return (Int)to_string(n).size();
}

Int f(Int a, Int b) {
    return max(digits(a), digits(b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Int n;
    cin >> n;

    vector<Int> divs = divisor(n);
    Int ans = INF;
    Int ro = divs.size();
    for (Int i = 0; i < ro; i++) {
        ans = min(ans, f(divs[i], divs[ro - i - 1]));
    }

    cout << ans << endl;

    return 0;
}