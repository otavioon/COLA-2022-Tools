#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    map<ll, ll> value2count;
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        value2count[A[i]]++;
    }

    ll target = 1;
    while (target <= 2 * 1e9) {
        target *= 2;
    }
    target /= 2;

    ll ans = 0;
    while (target > 0) {
        for (auto itr = value2count.rbegin(); itr != value2count.rend(); itr++) {
            ll opp = target - itr->first;
            if (value2count.count(opp)) {
                ll add = (itr->first != opp ? min(itr->second, value2count[opp])
                    : itr->second / 2 );
                ans += add;
                itr->second -= add;
                value2count[target - itr->first] -= add;
            }
        }

        target /= 2;
    }

    cout << ans << endl;
}