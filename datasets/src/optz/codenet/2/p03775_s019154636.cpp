#include <bits/stdc++.h>
using namespace std;
using LL  = long long;
using VI  = vector<LL>;
using VVI = vector<VI>;
using VB  = vector<bool>;
using VS  = vector<string>;
using PII = pair<LL, LL>;
using VP  = vector<PII>;
#define PB           push_back
#define MP           make_pair
#define SZ(a)        LL((a).size())
#define EACH(x, c)   for (auto x : (c))
#define ALL(c)       (c).begin(), (c).end()
#define REVERSE(c)   reverse(ALL(c))
#define SORT(c)      stable_sort(ALL(c))
#define RSORT(c)     stable_sort((c).rbegin(), (c).rend())
#define FSORT(c)     stable_sort(ALL(c), [] (auto& x, auto& y) {return x.first < y.first;});
#define FRSORT(c)    stable_sort(ALL(c), [] (auto& x, auto& y) {return x.first > y.first;});
#define SSORT(c)     stable_sort(ALL(c), [] (auto& x, auto& y) {return x.second < y.second;});
#define SRSORT(c)    stable_sort(ALL(c), [] (auto& x, auto& y) {return x.second > y.second;});
#define FOR(i, a, b) for (LL i = (a); i < (b); ++i)
#define REP(i, n)    FOR(i, 0, n)
#define DEBUG true
#define $(x) {if (DEBUG) {cout << #x << " = " << (x) << endl;}}

 VI listDivisors(LL n) {
    VI divs;
    FOR(i, 1, (LL)(sqrt(n) + 1)) {   // {1, n} を除く場合は2番目の引数を 2 にする
        if (n % i == 0) {
            divs.PB(i);
            divs.PB(n / i);
        }
    }
    SORT(divs);
    return divs;
}

inline LL nDigit(LL N) {
    LL ret = 0;
    while (N > 0) {
        ret++;
        N /= 10;
    }
    return ret;
}


int main() {
    LL N;
    cin >> N;
    VI divs = listDivisors(N);
    cout << nDigit(divs[SZ(divs) / 2]) << endl;

    return 0;
}
