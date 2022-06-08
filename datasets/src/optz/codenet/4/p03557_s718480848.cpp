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
    int N;
    cin>>N;
    vl A(N);
    vl B(N);
    vl C(N);
    rep(i, N){
        cin>>A[i];
    }
    rep(i, N){
        cin>>B[i];
    }
    rep(i, N){
        cin>>C[i];
    }
    sort(all(A));
    sort(all(C));
    ll ans = 0;
    ll a, c;
    rep(i, N){
        a = lower_bound(all(A), B[i]) - A.begin();
        c = C.end() - upper_bound(all(C), B[i]);
        ans += a * c;
    }
    cout<< ans <<endl;
}