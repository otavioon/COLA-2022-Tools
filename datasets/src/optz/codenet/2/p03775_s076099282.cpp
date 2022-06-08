#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;

ll N;

map<ll, ll> prime_factors(ll n) {
    map<ll, ll> res;
    if(n == 1) { // n=1 の素因数分解は n^1
        res[n] = 1;
        return res;
    }
    for(ll i = 2, _n = n; i*i <= _n; ++i) {
        while(n % i == 0) {
            ++res[i]; // 素数i^{res[i]}
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}
vector<ll> divisors(ll n) {
    vector<ll> res;
    for(ll i = 1; i*i <= n; ++i) {
        if(n % i != 0) continue;
        res.push_back(i);
        if(n/i == i) continue; // 上の行で追加済み。
        res.push_back(n/i);
    }
    return res;
}

int main() {
    cin >> N;
    vector<ll> v = divisors(N);
    sort(v.begin(), v.end());

    ll ans = 11;
    rep(i, v.size()) {
        // cout << v[i] << endl;
        ll other = N / v[i];
        ll tmp = max(to_string(v[i]).size(), to_string(other).size());
        ans = min(tmp, ans);
    }

    cout << ans << endl;
}