#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; (i) < ((int)(n)); ++(i))

int main() {
    ll ans;
    int N;
    ll K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    multimap<ll, int> mp;
    rep(i, N) mp.insert(make_pair(A[i], i));
    vector<int> Count(N, 1);
    rep(i, K) {
        auto itr = mp.end();
        itr--;
        int n = itr->second;
        mp.erase(itr);
        Count[n]++;
        ll x = (A[n] + Count[n] - 1) / Count[n];
        mp.insert(make_pair(x, n));
    }
    auto itr = mp.end();
    itr--;
    ans = itr->first;
    cout << ans << endl;
}