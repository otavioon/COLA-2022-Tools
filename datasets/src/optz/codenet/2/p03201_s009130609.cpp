#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    map<ll, ll> mp;
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]]++;
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    ll beki[32];
    beki[0] = 1;
    for(ll i = 1; i <= 30; i++) {
        beki[i] = beki[i - 1] * 2;
    }
    ll ans = 0;
    ll index = A.size();
    index--;
    for(ll i = 30; i >= 0; i--) {
        //cout << index << " " << i << " " << ans << endl;
        ll val;
        while(index > 0) {
            val = A[index];
            if(val < beki[i]) {
                i--;
                continue;
            }
            if(mp[val] == 0 || val >= 2 * beki[i]) {
                index--;
            } else break;
        }
        if(index == 0) break;
        if(val == beki[i]) {
            ans += mp[val] / 2;
            index--;
            i++;
            continue;
        }
        ll delta = min(mp[val], mp[2 * beki[i] - val]);
        mp[2 * beki[i] - val] -= delta;
        ans += delta;
        index--;
        i++;
    }
    cout << ans << endl;
    return 0;
}
