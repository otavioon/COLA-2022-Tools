#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N, K;
    cin >> N >> K;
    set<ll> D;
    for (ll i = 0; i < K; i++) {
        ll d;
        cin >> d;
        D.insert(d);
    }

    auto isOK = [&](ll x) {
        string s = to_string(x);
        for (char c : s) {
            if (D.count(c - '0')) {
                return false;
            }
        }
        return true;
    };

    for (ll i = N; ; i++) {
        if (isOK(i)) {
            cout << i << endl;
            return 0;
        }
    }
}