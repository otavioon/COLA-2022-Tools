#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

// 素因数分解 O(√n)
map<ll, ll> prime_factor(ll n) {
    map<ll, ll> res;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }

    if (n != 1) res[n] = 1;

    return res;
}

// 約数の列挙 O(√n)
vector<ll> divisor(ll n) {
    vector<ll> res;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }

    return res;
}

ll getdigit(ll n) {
    ll digit = 0;
    while (n != 0) {
        n /= 10;
        digit++;
    }

    return digit;
}

int main() {
    ll N;
    cin >> N;
    ll ans = INF;

    vector<ll> divs = divisor(N);
    repv(divs) {
        ll A = *it;
        ll B = N / A;
        ll Adig = getdigit(A);
        ll Bdig = getdigit(B);
        // cout << "A:" << A << ", B:" << B << ", Adig:" << Adig
        //      << ", Bdig:" << Bdig << endl;
        ans = min(ans, max(Adig, Bdig));
    }

    cout << ans << endl;

    // map<ll, ll> primes = prime_factor(N);
    // for (auto p : primes) {
    //     cout << p.first << "," << p.second << endl;
    // }

    return 0;
}