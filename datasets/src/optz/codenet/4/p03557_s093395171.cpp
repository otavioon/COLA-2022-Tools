#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define FOR(i, m, n) for(ll i = m; i < (n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>; 
using vl = vector<ll>;
using vll = vector<vl>;
using pll = pair<ll, ll>;


int main() {
    ll N;
    cin >> N;
    vl A(N), B(N), C(N);
    rep(i, N){
        cin >> A[i];
    }
    rep(i, N){
        cin >> B[i];
    }
    rep(i, N){
        cin >> C[i];
    }
    sort(all(A));
    sort(all(C));

    ll ans = 0;
    //中段を決めると全て決まる
    rep(i, N){
        ll a = lower_bound(all(A), B[i]) - A.begin();
        ll c = N - (upper_bound(all(C), B[i]) - C.begin());
        ans += a * c;
    }
    cout << ans << endl;
}