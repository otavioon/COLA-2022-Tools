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

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    if (a == 1 || b == 1) {
        if (a < b) {
            cout << "Alice" << endl;
        } else if (a > b) {
            cout << "Bob" << endl;
        } else {
            cout << "Draw" << endl;
        }
    } else {
        if (a < b) {
            cout << "Bob" << endl;
        } else if (a > b) {
            cout << "Alice" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }

    return 0;
}
