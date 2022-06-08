#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll n, k;
vector<ll> a;
bool check(ll x) {
    ll count = 0;
    rep1(i, n) count += (a[i] - 1) / x;
    if (count <= k) return true;
    else return false;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    rep1(i, n) cin >> a[i];
    ll ans = 0;
    ll left = 1, right = 1e9;
    while (right > left){
        ll mid = (right + left) / 2;
        if (check(mid)) right = mid;
        else left = mid+1;
    }  
    cout << left << endl;
}